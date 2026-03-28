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
};
