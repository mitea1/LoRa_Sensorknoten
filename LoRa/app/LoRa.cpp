/*
 * LoRa.cpp
 *
 *  Created on: May 31, 2016
 *      Author: Adrian
 */

#include "LoRa.h"

LoRa::LoRa(mDot* dot,RawSerial* debugSerial) {
	this->dot = dot;
	this->debugSerial = debugSerial;
}

LoRa::~LoRa() {
	// TODO Auto-generated destructor stub
}

void LoRa::init(){
    resetConfig();

    setPublicNetwork(true);
    setFrequencySubBand(config_frequency_sub_band);
    setNetworkName(config_network_name);
	setNetworkPassphrase(config_network_pass);
	setSpreadingFactor(mDot::SF_7);
    setAckRetries(1);
    dot->setTxPower(20);

    saveConfig();

    joinNetwork();
}

int32_t LoRa::setPublicNetwork(bool isPublic){
	int32_t ret;

	if ((ret = dot->setPublicNetwork(isPublic)) != mDot::MDOT_OK) {
	        debugSerial->printf("failed to set public network %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setFrequencySubBand(uint8_t frequencySubBand){
	int32_t ret;
	debugSerial->printf("setting frequency sub band\n");

	if ((ret = dot->setFrequencySubBand(frequencySubBand)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set frequency sub band %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setNetworkName(const std::string& networkName){
	int32_t ret;
	debugSerial->printf("setting network name\n");

	if ((ret = dot->setNetworkName(networkName)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set network name %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setNetworkPassphrase(const std::string& networkPassphrase){
	int32_t ret;
	debugSerial->printf("setting network password\n");

	if ((ret = dot->setNetworkPassphrase(networkPassphrase)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set network password %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setSpreadingFactor(const uint8_t& spreadingFactor){
	// a higher spreading factor allows for longer range but lower throughput
	// in the 915 (US) frequency band, spreading factors 7 - 10 are available
	// in the 868 (EU) frequency band, spreading factors 7 - 12 are available
	int32_t ret;

	debugSerial->printf("setting TX spreading factor\n");
	if ((ret = dot->setTxDataRate(spreadingFactor)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set TX datarate %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setAckRetries(const uint8_t& retries){
	int32_t ret;
	// request receive confirmation of packets from the gateway
	debugSerial->printf("enabling ACKs\n");
	if ((ret = dot->setAck(retries)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to enable ACKs %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

void LoRa::resetConfig(){
	dot->resetConfig();
}

void LoRa::saveConfig(){
	// save this configuration to the mDot's NVM
	debugSerial->printf("saving config\n");
	if (! dot->saveConfig()) {
		debugSerial->printf("failed to save configuration\n");
	}
}


int32_t LoRa::send(std::vector<uint8_t>& data){
	int32_t ret;
	ret=dot->send(data);
	if (ret != mDot::MDOT_OK) {
		debugSerial->printf("failed to send\n");
		debugSerial->printf(mDot::getReturnCodeString(ret).c_str());
		debugSerial->printf("\n");
	} else {
		debugSerial->printf("successfully sent data to gateway");

	}
	return ret;
}

int32_t LoRa::recv(std::vector<uint8_t>& data){
	return dot->recv(data);
}

void LoRa::joinNetwork(){
	int32_t ret;
    // attempt to join the network
    debugSerial->printf("joining network\n");
    while ((ret = dot->joinNetwork()) != mDot::MDOT_OK) {
        debugSerial->printf("failed to join network %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
        // in the 868 (EU) frequency band, we need to wait until another channel is available before transmitting again
        osDelay(std::max((uint32_t)1000, (uint32_t)dot->getNextTxMs()));
    }
    debugSerial->printf("Network joined\n");
}

