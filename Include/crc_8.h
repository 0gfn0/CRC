#ifndef CRC_8
#define CRC_8
#include "crc.h"
class CRC8 : public CRC<uint8_t> {
public:
	CRC8(uint8_t* input_message, size_t message_length);
	uint8_t calculate_crc() override;
	~CRC8();
private:
	void calculate_crc_table() override;
	uint8_t* crc_8_table;
	uint8_t polynom_8;
};
#endif

