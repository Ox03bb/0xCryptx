#include <cstdint>
#include <string>

#include <hashing/md5.h>
#include <utils.h>

using namespace std;

uint32_t md5::F(state s, uint8_t i) {
    if (i >= 0 && i <= 15) {
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


string hash(string raw, string key){

};