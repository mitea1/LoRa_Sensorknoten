/*
 * LoRaConfig.cpp
 *
 *  Created on: Jun 11, 2016
 *      Author: Adrian
 */

#include "LoRaConfig.h"

//LoRaConfig::LoRaConfig(){
//
//}
//
//LoRaConfig::~LoRaConfig(){
//
//}

void LoRaConfig::build(LORA_MODE desiredMode){
	switch(desiredMode){
	case LORA_MODE_0:
		setNetworkPublicity(true);
		setNetworkName(LORA_NETWORK_NAME);
		setNetworkPassphrase(LORA_NETWORK_PASSPHRASE);
		setFrequencySubBand(LORA_SUBBAND_0);
		setSpreadingFactor(LORA_SPREADING_FACTOR_7);
		setTxPowerdBm(LORA_TX_POWER_16_DBM);
		setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_0);
		break;
	case LORA_MODE_1:
		setNetworkPublicity(true);
		setNetworkName(LORA_NETWORK_NAME);
		setNetworkPassphrase(LORA_NETWORK_PASSPHRASE);
		setFrequencySubBand(LORA_SUBBAND_0);
		setSpreadingFactor(LORA_SPREADING_FACTOR_7);
		setTxPowerdBm(LORA_TX_POWER_16_DBM);
		setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_0);
		break;
	case LORA_MODE_2:
		setNetworkPublicity(true);
		setNetworkName(LORA_NETWORK_NAME);
		setNetworkPassphrase(LORA_NETWORK_PASSPHRASE);
		setFrequencySubBand(LORA_SUBBAND_0);
		setSpreadingFactor(LORA_SPREADING_FACTOR_7);
		setTxPowerdBm(LORA_TX_POWER_16_DBM);
		setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_0);
		break;
	case LORA_MODE_3:
		setNetworkPublicity(true);
		setNetworkName(LORA_NETWORK_NAME);
		setNetworkPassphrase(LORA_NETWORK_PASSPHRASE);
		setFrequencySubBand(LORA_SUBBAND_0);
		setSpreadingFactor(LORA_SPREADING_FACTOR_7);
		setTxPowerdBm(LORA_TX_POWER_16_DBM);
		setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_0);
		break;
	case LORA_MODE_4:
		setNetworkPublicity(true);
		setNetworkName(LORA_NETWORK_NAME);
		setNetworkPassphrase(LORA_NETWORK_PASSPHRASE);
		setFrequencySubBand(LORA_SUBBAND_0);
		setSpreadingFactor(LORA_SPREADING_FACTOR_7);
		setTxPowerdBm(LORA_TX_POWER_16_DBM);
		setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_0);
		break;
	case LORA_MODE_5:
		setNetworkPublicity(true);
		setNetworkName(LORA_NETWORK_NAME);
		setNetworkPassphrase(LORA_NETWORK_PASSPHRASE);
		setFrequencySubBand(LORA_SUBBAND_0);
		setSpreadingFactor(LORA_SPREADING_FACTOR_7);
		setTxPowerdBm(LORA_TX_POWER_16_DBM);
		setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_0);
		break;
	default:
		setNetworkPublicity(true);
		setNetworkName(LORA_NETWORK_NAME);
		setNetworkPassphrase(LORA_NETWORK_PASSPHRASE);
		setFrequencySubBand(LORA_SUBBAND_0);
		setSpreadingFactor(LORA_SPREADING_FACTOR_7);
		setTxPowerdBm(LORA_TX_POWER_16_DBM);
		setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_0);
		break;
	}
}

bool LoRaConfig::getPublicity(){
	return publicity;
}

std::string LoRaConfig::getNetworkName(){
	return *networkName;
}

std::string LoRaConfig::getNetworkPassphrase(){
	return *networkPassphrase;
}

uint8_t LoRaConfig::getFrequencySubBand(){
	return frequencySubBand;
}

uint8_t LoRaConfig::getSpreadingFactor(){
	return spreadingFactor;
}

uint8_t LoRaConfig::getTxPowerdBm(){
	return txPowerdBm;
}

uint8_t LoRaConfig::getAcknowledgeRetries(){
	return acknowledgeRetries;
}

void LoRaConfig::setNetworkPublicity(bool isPublic){
	this->publicity = isPublic;
}

void LoRaConfig::setNetworkName(char* networkName){
	this->networkName = new std::string(networkName);
}

void LoRaConfig::setNetworkPassphrase(char* networkPassphrase){
	this->networkPassphrase = new std::string(networkPassphrase);
}

void LoRaConfig::setFrequencySubBand(uint8_t frequencySubBand){
	this->frequencySubBand = frequencySubBand;
}

void LoRaConfig::setSpreadingFactor(uint8_t spreadingFactor){
	this->spreadingFactor = spreadingFactor;
}

void LoRaConfig::setTxPowerdBm(uint8_t txPowerdBm){
	this->txPowerdBm = txPowerdBm;
}

void LoRaConfig::setAcknowledgeRetries(uint8_t acknowledgeRetries){
	this->acknowledgeRetries = acknowledgeRetries;
}


