#include <cstdint>
#include <string>

#include <hashing/md5.h>
#include <utils.h>

using namespace std;

uint32_t K[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

uint8_t R[64] = {
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};


uint32_t md5::F(state s, uint8_t i) {
    if (i <= 15) {
        return (s.B & s.C) | ((~s.B) & s.D);
    } else if (i >= 16 && i <= 31) {
        return (s.D & s.B) | ((~s.D) & s.C);
    } else if (i >= 32 && i <= 47) {
        return s.B ^ s.C ^ s.D;
    } else if (i >= 48 && i <= 63) {
        return s.C ^ (s.B | (~s.D));
    }
    return 0;
};

uint32_t md5::l_rot(uint32_t in, uint8_t rot){
    return (in << rot) | (in >> (32 - rot));
}

uint32_t md5::r_rot(uint32_t in, uint8_t rot){
    return (in >> rot) | (in << (32 - rot));
}

uint32_t md5::H(uint32_t in, uint32_t B, uint8_t i) {
    in += K[i];
    in = l_rot(in, R[i]);
    return in + B;
};

uint32_t md5::combine(state s, uint32_t part, uint8_t i) {
    uint32_t f = md5::F(s, i);

    uint32_t tmp = s.A + f;

    tmp += part;

	return md5::H(tmp, s.B, i);
};


vector<array<uint32_t, 16>> md5::chunk(string raw) {
    size_t original_len = raw.size();
    uint64_t bit_len = original_len * 8;

    // Add '1' bit (0x80), then pad with zeros until length ≡ 56 mod 64
    raw += static_cast<char>(0x80);
    while ((raw.size() % 64) != 56) {
        raw += static_cast<char>(0x00);
    }

    // Append original length in bits as 64-bit little-endian integer
    for (int i = 0; i < 8; ++i) {
        raw += static_cast<char>((bit_len >> (8 * i)) & 0xFF);
    }

    vector<array<uint32_t, 16>> chunks;
    size_t num_chunks = raw.size() / 64;

    for (size_t i = 0; i < num_chunks; ++i) {
        array<uint32_t, 16> block{};
        for (size_t j = 0; j < 16; ++j) {
            // Each block is 4 bytes, little-endian
            size_t idx = i * 64 + j * 4;
            block[j] = static_cast<uint32_t>(static_cast<unsigned char>(raw[idx])) |
                       (static_cast<uint32_t>(static_cast<unsigned char>(raw[idx + 1])) << 8) |
                       (static_cast<uint32_t>(static_cast<unsigned char>(raw[idx + 2])) << 16) |
                       (static_cast<uint32_t>(static_cast<unsigned char>(raw[idx + 3])) << 24);
        }
        chunks.push_back(block);
    }

    return chunks;
}


string md5::hash(string raw){
    state s;

    auto blocks = md5::chunk(raw);

    for (auto &block : blocks) {
        state cur = s;

        for (uint8_t i = 0; i < 64; ++i) {
            uint32_t part;
            if (i <= 15) {
                part = block[i];
            } else if (i <= 31) {
                part = block[(5 * i + 1) % 16];
            } else if (i <= 47) {
                part = block[(3 * i + 5) % 16];
            } else {
                part = block[(7 * i) % 16];
            }

            uint32_t res = md5::combine(cur, part, i);

            // Rotate registers
            cur.A = cur.D;
            cur.D = cur.C;
            cur.C = cur.B;
            cur.B = res;
        }

        s.A += cur.A;
        s.B += cur.B;
        s.C += cur.C;
        s.D += cur.D;
    }

    auto to_hex_le = [](uint32_t val) {
        static const char hex[] = "0123456789abcdef";
        string out;
        for (int i = 0; i < 4; ++i) {
            uint8_t b = (val >> (8 * i)) & 0xFF;
            out.push_back(hex[(b >> 4) & 0xF]);
            out.push_back(hex[b & 0xF]);
        }
        return out;
    };

    string result;
    result += to_hex_le(s.A);
    result += to_hex_le(s.B);
    result += to_hex_le(s.C);
    result += to_hex_le(s.D);

    return result;
};