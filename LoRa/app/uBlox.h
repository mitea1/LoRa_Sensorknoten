/*
 * uBlox.h
 *
 *  Created on: 16.05.2016
 *      Author: Adrian
 */

#include <RawSerial.h>
#include <rtos.h>
#include "Decoder.h"
#include "uBloxConfig.h"

#ifndef APP_UBLOX_H_
#define APP_UBLOX_H_

typedef struct UBloxGPSMessage{
	float longitude;
	float latidute;
};


class uBlox {
public:
	uBlox(mbed::RawSerial*);
	void init(uBLOX_MODE);
	virtual ~uBlox();
	void getMessage();
	void writeMessage(char*);
	void setDebugSerial(mbed::RawSerial*);

	unsigned long getTimeOfWeekMs();
	float getLatitude();
	float getLongitude();
	signed long getHeightAboveEllipsoid();
	signed long getHeightAboveMeanSeaLevel();
	unsigned long getHorizontalAccuracyEstimate();
	unsigned long getVerticalAccuracyEstimate();

private:
	Decoder* decoder;
	mbed::RawSerial* serial;
	mbed::RawSerial* debug;
//	char* disableAllString;
//	char* enablePollhString;

	uBloxConfig* config;

	void buildSettingsStrings();
	void sendDisableEveryString();
	void sendEnablePollhString();

	void disableEveryMessage();
	void enablePollhMessage();


};

#endif /* APP_UBLOX_H_ */
