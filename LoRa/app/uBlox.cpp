/*
 * uBlox.cpp
 *
 *  Created on: 16.05.2016
 *      Author: Adrian
 */

#include "uBlox.h"

uBlox::uBlox(mbed::RawSerial* serial) {
	decoder = new Decoder(serial);
	this->serial = serial;
}

uBlox::~uBlox() {

}

void uBlox::setDebugSerial(mbed::RawSerial* debugSerial){
	this->debug = debugSerial;
}

void uBlox::getMessage(){
	POSLHH decodedPoslhh = decoder->getLastPoslhh();

	debug->printf("DECODED MESSAGE:\n");
	debug->printf("iTOW:%lu\n",getTimeOfWeekMs());
	debug->printf("lon:%ld\n",getLongitude());
	debug->printf("lat:%ld\n",getLatitude());
	debug->printf("height:%ld\n",getHeightAboveEllipsoid());
	debug->printf("hMSL:%ld\n",getHeightAboveMeanSeaLevel());
	debug->printf("hAcc:%lu\n",getHorizontalAccuracyEstimate());
	debug->printf("vAcc:%lu\n\n",getVerticalAccuracyEstimate());
	debug->printf("BYTE CODE:%s\n\n",decoder->getReceiveBuffer());
}

unsigned long uBlox::getTimeOfWeekMs(){
	return decoder->getLastPoslhh().iTOW;
}

signed long uBlox::getLongitude(){
	return decoder->getLastPoslhh().lon;
}

signed long uBlox::getLatitude(){
	return decoder->getLastPoslhh().lat;
}

signed long uBlox::getHeightAboveEllipsoid(){
	return decoder->getLastPoslhh().height;
}

signed long uBlox::getHeightAboveMeanSeaLevel(){
	return decoder->getLastPoslhh().hMSL;
}

unsigned long uBlox::getHorizontalAccuracyEstimate(){
	return decoder->getLastPoslhh().hAcc;
}

unsigned long uBlox::getVerticalAccuracyEstimate(){
	return decoder->getLastPoslhh().vAcc;
}


void uBlox::writeMessage(char* string){
	serial->printf("Test");
}

void uBlox::init(){
	sendDisableEveryString();
	osDelay(10);
	sendEnablePollhString();
	osDelay(10);
}

void uBlox::buildSettingsStrings(){

}

void uBlox::sendDisableEveryString(){
	int i;
	uint8_t disableString[28]={0xB5,0x62,0x06,0x00,0x14,0x00,0x01,0x00,0x00,0x00,0xD0,0x08,0x00,0x00,0x80,0x25,0x00,0x00,0x01,0x00,0x01,
			0x00,0x00,0x00,0x00,0x00,0x9A,0x79};
	for(i=0;i<28;i++){
		serial->putc(disableString[i]);
	}
}

void uBlox::sendEnablePollhString(){
	int i;
		uint8_t enablePollhString[16]={0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x02,0x00,0x01,0x00,0x00,0x00,0x00,0x13,0xBE};
		for(i=0;i<16;i++){
			serial->putc(enablePollhString[i]);
		}
}

