/*
 * MAX44009Message.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef MAX44009MESSAGE_H_
#define MAX44009MESSAGE_H_

#include <string>
#include <vector>
#include <stdio.h>
#include "SensorMessage.h"

class MAX44009Message:public SensorMessage {
public:
	MAX44009Message();
	virtual ~MAX44009Message();

	void setLux(float);
	float getLux();

	virtual char* getLoRaMessageString();
private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float lux;

	virtual char* getLoRaMessageId();
};

#endif /* MAX44009MESSAGE_H_ */
