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
	this->config = new uBloxConfig();
}

uBlox::~uBlox() {

}

unsigned long uBlox::getTimeOfWeekMs(){
	return decoder->getLastPoslhh().iTOW;
}

float uBlox::getLongitude(){
	return (float) (decoder->getLastPoslhh().lon) / 10000000;
}

float uBlox::getLatitude(){
	return (float) (decoder->getLastPoslhh().lat) / 10000000;
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

void uBlox::init(uBLOX_MODE desiredMode){
	//TODO initialize depending on chosen Mode
	sendDisableEveryString();
	osDelay(100);
	sendEnablePosllhString();
	osDelay(100);
}

void uBlox::sendDisableEveryString(){
	int i;
	uint8_t disableString[28]={0xB5,0x62,0x06,0x00,0x14,0x00,0x01,0x00,0x00,0x00,0xD0,0x08,0x00,0x00,0x80,0x25,0x00,0x00,0x01,0x00,0x01,
			0x00,0x00,0x00,0x00,0x00,0x9A,0x79};
	for(i=0;i<28;i++){
		serial->putc(disableString[i]);
	}
}

void uBlox::sendEnablePosllhString(){
	int i;
		uint8_t enablePollhString[16]={0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x02,0x00,0x01,0x00,0x00,0x00,0x00,0x13,0xBE};
		for(i=0;i<16;i++){
			serial->putc(enablePollhString[i]);
		}
}

