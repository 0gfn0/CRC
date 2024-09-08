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

class CRC8 : public CRC<uint8_t>{
public:
	CRC8(uint8_t* input_message, size_t message_length);
	uint8_t calculate_crc() override;
	~CRC8();
private:
	void calculate_crc_table() override;
	uint8_t *crc_8_table;
	uint8_t polynom_8;
};

class CRC16 : public CRC<uint16_t>
{
public:
	CRC16(uint8_t* input_message, size_t message_length);
	uint16_t calculate_crc() override;
	~CRC16();
private:
	void calculate_crc_table() override;
	uint16_t* crc_16_table;
	uint16_t polynom_16;
};

class CRC32 : public CRC <uint32_t>
{
public:
	CRC32(uint8_t* input_message, size_t message_length);
	uint32_t calculate_crc() override;
	~CRC32();
private:
	void calculate_crc_table() override;
	uint32_t* crc_32_table;
	uint32_t polynom_32;
};
#endif

