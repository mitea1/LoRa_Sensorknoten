/*
 * LoRaConfig.h
 *
 *  Created on: Jun 11, 2016
 *      Author: Adrian
 */

#include <string>
#include <stdint-gcc.h>
#ifndef LORACONFIG_H_
#define LORACONFIG_H_

#define LORA_NETWORK_NAME				"conduitgwy"
#define LORA_NETWORK_PASSPHRASE			"conduitgwy"

#define LORA_SUBBAND_0						0
#define LORA_SUBBAND_1						1
#define LORA_SUBBAND_2						2
#define LORA_SUBBAND_3						3
#define LORA_SUBBAND_4						4
#define LORA_SUBBAND_5						5
#define LORA_SUBBAND_6						6
#define LORA_SUBBAND_7						7
#define LORA_SUBBAND_8						8

#define LORA_SPREADING_FACTOR_7				7
#define LORA_SPREADING_FACTOR_8				8
#define LORA_SPREADING_FACTOR_9				9
#define LORA_SPREADING_FACTOR_10			10
#define LORA_SPREADING_FACTOR_11			11
#define LORA_SPREADING_FACTOR_12			12

#define LORA_TX_POWER_2_DBM					2
#define LORA_TX_POWER_4_DBM					4
#define LORA_TX_POWER_8_DBM					8
#define LORA_TX_POWER_16_DBM				16
#define LORA_TX_POWER_20_DBM				20

#define LORA_ACKNOWLEDGE_RETRIES_0			0
#define LORA_ACKNOWLEDGE_RETRIES_1			1
#define LORA_ACKNOWLEDGE_RETRIES_2			2

enum LORA_MODE{
	LORA_MODE_0 = 0,
	LORA_MODE_1 = 1,
	LORA_MODE_2 = 2,
	LORA_MODE_3 = 3,
	LORA_MODE_4 = 4,
	LORA_MODE_5 = 5,
};

class LoRaConfig {
public:
	LoRaConfig();
	virtual ~LoRaConfig();
	void build(LORA_MODE);

	bool isPublic();
	bool isActiv();
	std::string getNetworkName();
	std::string getNetworkPassphrase();
	uint8_t getFrequencySubBand();
	uint8_t getSpreadingFactor();
	uint8_t getTxPowerdBm();
	uint8_t getAcknowledgeRetries();

	LORA_MODE getLORA_MODE();


private:
	std::string* networkName;
	std::string* networkPassphrase;
	bool publicity;
	bool activity;
	uint8_t frequencySubBand;
	uint8_t spreadingFactor;
	uint8_t txPowerdBm;
	uint8_t acknowledgeRetries;

	LORA_MODE loraMode;


	void setNetworkPublicity(bool);
	void setActivity(bool);
	void setNetworkName(char*);
	void setNetworkPassphrase(char*);
	void setFrequencySubBand(uint8_t);
	void setSpreadingFactor(uint8_t);
	void setTxPowerdBm(uint8_t);
	void setAcknowledgeRetries(uint8_t);

	void setLORA_MODE(LORA_MODE);

};

#endif /* LORACONFIG_H_ */
