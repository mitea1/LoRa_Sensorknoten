/*
 * LoRaMeasuermentMessage.h
 *
 *  Created on: 13.06.2016
 *      Author: Adrian
 */

#ifndef APP_LORAMEASUERMENTMESSAGE_H_
#define APP_LORAMEASUERMENTMESSAGE_H_

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

class LoRaMeasuermentMessage: public SensorMessage {
public:
	LoRaMeasuermentMessage();
	virtual ~LoRaMeasuermentMessage();

	void setRssi(int16_t);
	int16_t getRssi();
	void setSnr(int16_t);
	int16_t getSnr();
	void setSpreadingFactor(uint8_t);
	uint8_t getSpreadingFactor();
	void setTxPowerdBm(uint8_t);
	uint8_t getTxPowerdBm();

	virtual char* getLoRaMessageString();
	virtual char* getLoRaMessageId();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	int16_t rssi;
	int16_t snr;
	uint8_t spreadingFactor;
	uint8_t txPowerdBm;


};

#endif /* APP_LORAMEASUERMENTMESSAGE_H_ */
