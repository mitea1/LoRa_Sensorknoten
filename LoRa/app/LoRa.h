/*
 * LoRa.h
 *
 *  Created on: May 31, 2016
 *      Author: Adrian
 */
#include "mDot.h"
#include "MTSLog.h"

#ifndef LORA_H_
#define LORA_H_

class LoRa {
public:
	LoRa(mDot*,RawSerial*);
	virtual ~LoRa();

	void init();

	int32_t send(std::vector<uint8_t>&);
	int32_t recv(std::vector<uint8_t>&);


private:
	mDot* dot;
	RawSerial* debugSerial;

	std::string config_network_name = "conduitgwy";
	std::string config_network_pass = "conduitgwy";
	uint8_t config_frequency_sub_band = 1;

	int32_t setPublicNetwork(bool);
	int32_t setFrequencySubBand(uint8_t);
	int32_t setNetworkName(const std::string&);
	int32_t setNetworkPassphrase(const std::string&);
	int32_t setSpreadingFactor(const uint8_t&);
	int32_t setAckRetries(const uint8_t&);
	void saveConfig();
	void resetConfig();
	void joinNetwork();



};

#endif /* LORA_H_ */
