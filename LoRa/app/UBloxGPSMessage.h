/*
 * UBloxGPSMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef UBLOXGPSMESSAGE_H_
#define UBLOXGPSMESSAGE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

class UBloxGPSMessage: public SensorMessage {
public:
	UBloxGPSMessage();
	virtual ~UBloxGPSMessage();

	void setLongitude(float);
	void setLatitude(float);
	float getLongitude();
	float getLatitude();

	virtual char* getLoRaMessageString();
	virtual char* getLoRaMessageId();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float longitude;
	float latitude;
};


#endif /* UBLOXGPSMESSAGE_H_ */
