/*
 * BME280HumidityMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef BME280HUMIDITYMESSAGE_H_
#define BME280HUMIDITYMESSAGE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

class BME280HumidityMessage: public SensorMessage {
public:
	BME280HumidityMessage();
	virtual ~BME280HumidityMessage();

	void setHumidity(float);
	float getHumidity();

	virtual char* getLoRaMessageString();
	virtual char* getLoRaMessageId();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float humidity;
};

#endif /* BME280HUMIDITYMESSAGE_H_ */
