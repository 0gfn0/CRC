#include "crc.h"

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
	for (short index = 0; index < 256; index++){
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

CRC32::CRC32(uint8_t* input_message, size_t message_length) : polynom_32(crc32_polynom){
	data_length = message_length;
	calculate_crc_table();
	data = new uint8_t[data_length];
	for (size_t i = 0; i < data_length; ++i) {
		data[i] = input_message[i];
	}
}
void CRC32::calculate_crc_table(){
	crc_32_table = new uint32_t[256];

	for (short index = 0; index < 256; index++) {
		uint32_t current_byte = static_cast<uint32_t>(index) << 24;
		for (uint8_t bit = 0; bit < 8; bit++){
			if (current_byte & crc32_high_bit){
				current_byte <<= 1;
				current_byte ^= polynom_32;
			}
			else{
				current_byte <<= 1;
			}
		}
		crc_32_table[index] = current_byte;
	}
}
uint32_t CRC32::calculate_crc(){
	uint32_t crc = initial_value_crc_32;
	for (size_t i = 0; i < data_length; i++) {
		uint8_t index = static_cast<uint8_t>((crc >> 24) ^ data[i]);
		crc = (crc << 8) ^ crc_32_table[index];
	}
	return crc ^ final_xor_value_crc32;
}

int main()
{
	uint8_t data_32[] = { 0xFF, 0xFA, 0xFF, 0x02};
	CRC32 crc32(data_32, sizeof(data_32));
	std::cout << std::hex << static_cast<int>(crc32.calculate_crc());

	return 0;
}

CRC8::~CRC8(){
	delete[] data;
	data = nullptr;

	delete[] crc_8_table;
	crc_8_table = nullptr;
}

CRC16::~CRC16(){
	delete[] data;
	data = nullptr;

	delete[] crc_16_table;
	crc_16_table = nullptr;
}

CRC32::~CRC32() {
	delete[] data;
	data = nullptr;

	delete[] crc_32_table;
	crc_32_table = nullptr;
}


