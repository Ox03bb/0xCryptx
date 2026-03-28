#ifndef MD5_H
#define MD5_H

#include <cstdint>
#include <string>

using namespace std;


struct state {
	uint32_t A = 0x67452301;
	uint32_t B = 0xEFCDAB89;
	uint32_t C = 0x98BADCFE;
	uint32_t D = 0x10325476;
};

struct output{
	uint64_t high;
	uint64_t low;
};


// i % 16
// (5i + 1) % 16
// (3i + 1) % 16
// 7i % 16


class md5{
	public:
		static string hash(string raw , string key);

	private:
		static uint32_t r_rot(uint32_t in ,uint8_t shift);
		static uint32_t l_rot(uint32_t in ,uint8_t shift);

		static uint32_t combine(state s, uint32_t part, uint8_t i);
		static uint32_t F(state s, uint8_t i);

};


#endif // MD5_H