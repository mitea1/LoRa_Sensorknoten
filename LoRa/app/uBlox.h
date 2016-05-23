/*
 * uBlox.h
 *
 *  Created on: 16.05.2016
 *      Author: Adrian
 */

#ifndef APP_UBLOX_H_
#define APP_UBLOX_H_

#include <RawSerial.h>
#include <rtos.h>
#include "Decoder.h"


class uBlox {
public:
	uBlox(mbed::RawSerial*);
	void init();
	virtual ~uBlox();
	void getMessage();
	void writeMessage(char*);
	void setDebugSerial(mbed::RawSerial*);

	unsigned long getTimeOfWeekMs();
	signed long getLatitude();
	signed long getLongitude();
	signed long getHeightAboveEllipsoid();
	signed long getHeightAboveMeanSeaLevel();
	unsigned long getHorizontalAccuracyEstimate();
	unsigned long getVerticalAccuracyEstimate();

private:
	Decoder* decoder;
	mbed::RawSerial* serial;
	mbed::RawSerial* debug;
	char* disableAllString;
	char* enablePollhString;

	void buildSettingsStrings();
	void sendDisableEveryString();
	void sendEnablePollhString();

	void disableEveryMessage();
	void enablePollhMessage();


};

#endif /* APP_UBLOX_H_ */
