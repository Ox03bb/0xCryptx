#include <cstdint>

uint32_t l_rot(uint32_t in ,uint8_t rot){
	return (in << rot) | in >> (32 - rot);
};

uint32_t r_rot(uint32_t in ,uint8_t rot){
	return (in >> rot) | in << (32 - rot);
};