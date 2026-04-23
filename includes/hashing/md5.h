#ifndef MD5_H
#define MD5_H

#include <cstdint>
#include <string>
#include <vector>
#include <array>

using namespace std;

struct state {
    uint32_t A = 0x67452301;
    uint32_t B = 0xEFCDAB89;
    uint32_t C = 0x98BADCFE;
    uint32_t D = 0x10325476;
};

struct output {
    uint64_t high;
    uint64_t low;
};

extern uint32_t K[64];

extern uint8_t R[64];

class md5 {
  public:
    static string hash(string raw);

  private:
    static uint32_t r_rot(uint32_t in, uint8_t rot);
    static uint32_t l_rot(uint32_t in, uint8_t rot);

    static uint32_t combine(state s, uint32_t part, uint8_t i);
    static uint32_t F(state s, uint8_t i);
    static uint32_t H(uint32_t in, uint32_t B, uint8_t i);

	static vector<array<uint32_t, 16>> chunk(string raw);
};

#endif // MD5_H