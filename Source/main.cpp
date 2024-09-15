#include "crc_include.h"
int main()
{
	uint8_t data_32[] = { 0xFF, 0xFA, 0xFF, 0x02};
	CRC32 crc32(data_32, sizeof(data_32));
	std::cout << std::hex << static_cast<int>(crc32.calculate_crc());

	return 0;
}

