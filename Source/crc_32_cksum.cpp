#include "crc_32_cksum.h"
CRC32::CRC32(uint8_t* input_message, size_t message_length) : polynom_32(crc32_polynom) {
	data_length = message_length;
	calculate_crc_table();
	data = new uint8_t[data_length];
	for (size_t i = 0; i < data_length; ++i) {
		data[i] = input_message[i];
	}
}
void CRC32::calculate_crc_table() {
	crc_32_table = new uint32_t[256];

	for (short index = 0; index < 256; index++) {
		uint32_t current_byte = static_cast<uint32_t>(index) << 24;
		for (uint8_t bit = 0; bit < 8; bit++) {
			if (current_byte & crc32_high_bit) {
				current_byte <<= 1;
				current_byte ^= polynom_32;
			}
			else {
				current_byte <<= 1;
			}
		}
		crc_32_table[index] = current_byte;
	}
}
uint32_t CRC32::calculate_crc() {
	uint32_t crc = initial_value_crc_32;
	for (size_t i = 0; i < data_length; i++) {
		uint8_t index = static_cast<uint8_t>((crc >> 24) ^ data[i]);
		crc = (crc << 8) ^ crc_32_table[index];
	}
	return crc ^ final_xor_value_crc32;
}
CRC32::~CRC32() {
	delete[] data;
	data = nullptr;

	delete[] crc_32_table;
	crc_32_table = nullptr;
}
