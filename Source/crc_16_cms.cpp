#include "crc_16_cms.h"
CRC16::CRC16(uint8_t* input_message, size_t message_length) : polynom_16(crc16_polynom)
{
	data_length = message_length;
	calculate_crc_table();
	data = new uint8_t[data_length];
	for (size_t i = 0; i < data_length; ++i) {
		data[i] = input_message[i];
	}
}
void CRC16::calculate_crc_table()
{
	crc_16_table = new uint16_t[256];
	for (short index = 0; index < 256; index++) {
		uint16_t current_byte = static_cast<uint16_t>(index) << 8;
		for (uint8_t bit = 0; bit < 8; bit++) {
			if (current_byte & crc16_high_bit) {
				current_byte = (current_byte << 1) ^ polynom_16;
			}
			else {
				current_byte <<= 1;
			}
		}
		crc_16_table[index] = current_byte;
	}
}
uint16_t CRC16::calculate_crc()
{
	uint16_t crc = initial_value_crc_16;

	for (size_t i = 0; i < data_length; i++) {
		uint8_t index = (crc >> 8) ^ (data[i] & cut_higher_bites);
		crc = (crc << 8) ^ crc_16_table[index];
	}
	return crc;
}

CRC16::~CRC16() {
	delete[] data;
	data = nullptr;

	delete[] crc_16_table;
	crc_16_table = nullptr;
}