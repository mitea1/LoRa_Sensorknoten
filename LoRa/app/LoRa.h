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

	int16_t getLastRssi();
	int16_t getLastSnr();

	uint8_t getSpreadingFactor();
	uint8_t getTxPowerdBm();

	void ping();



private:
	mDot* dot;
	RawSerial* debugSerial;

	LoRaConfig* config;

	int16_t rssi;
	int16_t snr;
	uint8_t spreadingFactor;
	uint8_t txPowerdBm;

	int32_t setPublicNetwork();
	int32_t setFrequencySubBand();
	int32_t setNetworkName();
	int32_t setNetworkPassphrase();
	int32_t setSpreadingFactor();
	int32_t setAckRetries();
	int32_t setTxPower();
	void saveConfig();
	void resetConfig();
	void joinNetwork();



};

#endif /* LORA_H_ */
