#ifndef CRC_32_POSIX
#define CRC_32_POSIX
#include "crc.h"
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