/*
 * BME280TemperatureMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef BME280TEMPERATUREMESSAGE_H_
#define BME280TEMPERATUREMESSAGE_H_


#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"


class BME280TemperatureMessage: public SensorMessage {
public:
	BME280TemperatureMessage();
	virtual ~BME280TemperatureMessage();

	void setTemperature(float);
	float getTemperature();

	virtual char* getLoRaMessageString();
	virtual char* getLoRaMessageId();
private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float temperature;
};

#endif /* BME280TEMPERATUREMESSAGE_H_ */
