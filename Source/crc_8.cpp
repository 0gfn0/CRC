#include "crc_8.h"
CRC8::CRC8(uint8_t* input_message, size_t message_length) : polynom_8(crc8_polynom) {
	data_length = message_length;
	calculate_crc_table();
	data = new uint8_t[data_length];
	for (size_t i = 0; i < data_length; ++i) {
		data[i] = input_message[i];
	}
}
void CRC8::calculate_crc_table()
{
	crc_8_table = new uint8_t[256];
	for (short index = 0; index < 256; index++) {

		uint8_t current_byte = index;

		for (uint8_t bit = 0; bit < 8; bit++) {
			if (current_byte & crc8_high_bit) {
				current_byte = (current_byte << 1) ^ polynom_8;
			}
			else {
				current_byte <<= 1;
			}
		}
		crc_8_table[index] = current_byte;
	}
}
uint8_t CRC8::calculate_crc() {
	uint8_t crc = initial_value_crc_8;

	for (size_t i = 0; i < data_length; i++) {
		uint8_t index = data[i] ^ crc;
		crc = crc_8_table[index];
	}
	return crc;
}

CRC8::~CRC8() {
	delete[] data;
	data = nullptr;

	delete[] crc_8_table;
	crc_8_table = nullptr;
}