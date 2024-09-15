#ifndef CRC_16_CMS
#define CRC_16_CMS
#include "crc.h"
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
#endif

