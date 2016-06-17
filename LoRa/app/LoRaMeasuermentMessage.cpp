/*
 * LoRaMeasuermentMessage.cpp
 *
 *  Created on: 13.06.2016
 *      Author: Adrian
 */

#include "LoRaMeasuermentMessage.h"
#include "main.h"

LoRaMeasuermentMessage::LoRaMeasuermentMessage() {
	loraMessageId.push_back(LORA_MEASURMENT_RSSI_MESSAGE_ID);
	loraMessageId.push_back(LORA_MEASURMENT_SNR_MESSAGE_ID);
	loraMessageId.push_back(LORA_MEASURMENT_SPREADING_FACTOR_MESSAGE_ID);
	loraMessageId.push_back(LORA_MEASURMENT_TX_POWER_MESSAGE_ID);

}

LoRaMeasuermentMessage::~LoRaMeasuermentMessage() {
	// TODO Auto-generated destructor stub
}

void LoRaMeasuermentMessage::setRssi(int16_t rssi){
	this->rssi = rssi;
}

int16_t LoRaMeasuermentMessage::getRssi(){
	return rssi;
}

void LoRaMeasuermentMessage::setSnr(int16_t snr){
	this->snr = snr;
}

int16_t LoRaMeasuermentMessage::getSnr(){
	return snr;
}

void LoRaMeasuermentMessage::setSpreadingFactor(uint8_t spreadingFactor){
	this->spreadingFactor = spreadingFactor;
}

uint8_t LoRaMeasuermentMessage::getSpreadingFactor(){
	return spreadingFactor;
}

void LoRaMeasuermentMessage::setTxPowerdBm(uint8_t txPowerdBm){
	this->txPowerdBm = txPowerdBm;
}

uint8_t LoRaMeasuermentMessage::getTxPowerdBm(){
	return txPowerdBm;
}

char* LoRaMeasuermentMessage::getLoRaMessageString(){
	char buffer[20];
	loraMessage.clear();
	sprintf(buffer,"%s:%d,",loraMessageId.at(0).c_str(),getRssi());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%d,",loraMessageId.at(1).c_str(),getSnr());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%d,",loraMessageId.at(2).c_str(),getSpreadingFactor());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%d,",loraMessageId.at(3).c_str(),getTxPowerdBm());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

char* LoRaMeasuermentMessage::getLoRaMessageId(){

}
