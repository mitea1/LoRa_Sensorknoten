/*
 * BME280PressureMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef BME280PRESSUREMESSAGE_H_
#define BME280PRESSUREMESSAGE_H_
#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

class BME280PressureMessage: public SensorMessage {
public:
	BME280PressureMessage();
	virtual ~BME280PressureMessage();

	void setPressure(float);
	float getPressure();


	virtual char* getLoRaMessageString();
	virtual char* getLoRaMessageId();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float pressure;
};

#endif /* BME280PRESSUREMESSAGE_H_ */
