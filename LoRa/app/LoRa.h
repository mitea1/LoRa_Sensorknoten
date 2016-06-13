/*
 * LoRa.h
 *
 *  Created on: May 31, 2016
 *      Author: Adrian
 */
#include "mDot.h"
#include "MTSLog.h"
#include "LoRaConfig.h"

#ifndef LORA_H_
#define LORA_H_

class LoRa {
public:
	LoRa(mDot*,RawSerial*);
	virtual ~LoRa();

	void init(LORA_MODE);

	int32_t send(std::vector<uint8_t>&);
	int32_t recv(std::vector<uint8_t>&);


private:
	mDot* dot;
	RawSerial* debugSerial;

	LoRaConfig* config;

	int32_t setPublicNetwork();
	int32_t setFrequencySubBand();
	int32_t setNetworkName();
	int32_t setNetworkPassphrase();
	int32_t setSpreadingFactor();
	int32_t setAckRetries();
	void saveConfig();
	void resetConfig();
	void joinNetwork();



};

#endif /* LORA_H_ */
