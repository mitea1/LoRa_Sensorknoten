/*
 * SI1143Message.h
 *
 *  Created on: 02.06.2016
 *      Author: Adrian
 */
#include <stdio.h>
#include <string>
#include <vector>
#include <stdint.h>
#include "SensorMessage.h"

#ifndef APP_SI1143MESSAGE_H_
#define APP_SI1143MESSAGE_H_

#define SI1143_PROXIMITY_MESSAGE_ID		"P"

class SI1143ProximityMessage: public SensorMessage {
public:
	SI1143ProximityMessage();
	virtual ~SI1143ProximityMessage();

	void setProximity(uint16_t);
	uint16_t getProximity();

	virtual char* getLoRaMessageString();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	uint16_t proximity;

	virtual char* getLoRaMessageId();
};

#endif /* APP_SI1143MESSAGE_H_ */
