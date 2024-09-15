#ifndef CRC_H
#define CRC_H
#include <cstdint>
#include <iostream>

enum Variables
{
	cut_higher_bites = 0xFF,
	final_xor_value_crc32 = 0xFFFFFFFF,

	crc8_polynom = 0x07,
	crc16_polynom = 0x8005,
	crc32_polynom = 0x04C11DB7,

	initial_value_crc_8 = 0,
	initial_value_crc_16 = 0xFFFF,
	initial_value_crc_32 = 0x00000000,

	crc8_high_bit = 0x80,
	crc16_high_bit = 0x8000,
	crc32_high_bit = 0x80000000,
};

template <typename memory_type>
class CRC{
public:
	virtual memory_type calculate_crc() = 0;
protected:
	virtual void calculate_crc_table() = 0;
	size_t data_length;
	uint8_t* data;
};
#endif

