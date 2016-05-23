/*
 * Decoder.h
 *
 *  Created on: 16.05.2016
 *      Author: Adrian
 */

#ifndef APP_DECODER_H_
#define APP_DECODER_H_

#include <RawSerial.h>

#define HEADER_LENGHT 2
#define ID_LENGHT 2
#define LENGHT_LENGHT 2
#define PAYLOAD_LENGHT 28
#define CRC_LENGHT 2
#define MESSAGE_LENGHT (HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+PAYLOAD_LENGHT+CRC_LENGHT)


enum DecoderState{
	INIT = 0,
	RECEIVE,
	DECODE,
};

typedef struct POSLHH{
	unsigned long iTOW;
	long lon;
	long lat;
	long height;
	long hMSL;
	unsigned long hAcc;
	unsigned long vAcc;
};

class Decoder {
public:
	Decoder(mbed::RawSerial*);
	virtual ~Decoder();
	DecoderState getActualState();
	char* getReceiveBuffer();
	POSLHH getLastPoslhh();

private:
	DecoderState actualState;
	mbed::RawSerial* serial;
	char lastReceivedChar;
	POSLHH lastPoslhh;
	char receiveBuffer[MESSAGE_LENGHT];
	int bufferPosition;

	void setActualState(DecoderState);
	void getCharacterFromSerial();
	bool hasReceived(char);
	void bufferReceivedCharacterAtBegin();
	void bufferReceivedCharacter();
	bool isBufferFilled();
	void rxInterrupt();
	void setBufferPosition(uint8_t);
	void incrementBufferPosition();
	void clearReceiveBuffer();
	void decodeReceiveBuffer();
};

#endif /* APP_DECODER_H_ */
