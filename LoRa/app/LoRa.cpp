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
	int32_t ret;
    //*******************************************
    // configuration
    //*******************************************
    // reset to default config so we know what state we're in
    dot->resetConfig();
    dot->setLogLevel(mts::MTSLog::INFO_LEVEL);

    // set up the mDot with our network information: frequency sub band, network name, and network password
    // these can all be saved in NVM so they don't need to be set every time - see mDot::saveConfig()

    // frequency sub band is only applicable in the 915 (US) frequency band
    // if using a MultiTech Conduit gateway, use the same sub band as your Conduit (1-8) - the mDot will use the 8 channels in that sub band
    // if using a gateway that supports all 64 channels, use sub band 0 - the mDot will use all 64 channels

    if ((ret = dot->setPublicNetwork(true)) != mDot::MDOT_OK) {
        debugSerial->printf("failed to set public network %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
    }

    debugSerial->printf("setting frequency sub band\n");
    if ((ret = dot->setFrequencySubBand(config_frequency_sub_band)) != mDot::MDOT_OK) {
        debugSerial->printf("failed to set frequency sub band %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
    }

    debugSerial->printf("setting network name\n");
    if ((ret = dot->setNetworkName(config_network_name)) != mDot::MDOT_OK) {
        debugSerial->printf("failed to set network name %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
    }

    debugSerial->printf("setting network password\n");
    if ((ret = dot->setNetworkPassphrase(config_network_pass)) != mDot::MDOT_OK) {
        debugSerial->printf("failed to set network password %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
    }

    // a higher spreading factor allows for longer range but lower throughput
    // in the 915 (US) frequency band, spreading factors 7 - 10 are available
    // in the 868 (EU) frequency band, spreading factors 7 - 12 are available
    debugSerial->printf("setting TX spreading factor\n");
    if ((ret = dot->setTxDataRate(mDot::SF_10)) != mDot::MDOT_OK) {
        debugSerial->printf("failed to set TX datarate %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
    }

    // request receive confirmation of packets from the gateway
    debugSerial->printf("enabling ACKs\n");
    if ((ret = dot->setAck(1)) != mDot::MDOT_OK) {
        debugSerial->printf("failed to enable ACKs %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
    }

    // save this configuration to the mDot's NVM
    debugSerial->printf("saving config\n");
    if (! dot->saveConfig()) {
        debugSerial->printf("failed to save configuration\n");
    }

    joinNetwork();
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

