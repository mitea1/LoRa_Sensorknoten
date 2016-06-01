/*
 * MPU9250AccelerationMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef MPU9250ACCELERATIONMESSAGE_H_
#define MPU9250ACCELERATIONMESSAGE_H_
#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

class MPU9250AccelerationMessage: public SensorMessage {
public:
	MPU9250AccelerationMessage();
	virtual ~MPU9250AccelerationMessage();

	void setXAcceleration(float);
	void setYAcceleration(float);
	void setZAcceleration(float);

	float getXAcceleration();
	float getYAcceleration();
	float getZAcceleration();

	virtual char* getLoRaMessageString();

private:

	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float xAcceleration;
	float yAcceleration;
	float zAcceleration;

	virtual char* getLoRaMessageId();
};

#endif /* MPU9250ACCELERATIONMESSAGE_H_ */
