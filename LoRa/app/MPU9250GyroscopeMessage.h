/*
 * MPU9250GyroscopeMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef MPU9250GYROSCOPEMESSAGE_H_
#define MPU9250GYROSCOPEMESSAGE_H_
#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

class MPU9250GyroscopeMessage: public SensorMessage {
public:
	MPU9250GyroscopeMessage();
	virtual ~MPU9250GyroscopeMessage();

	void setXGyro(float);
	void setYGyro(float);
	void setZGyro(float);

	float getXGyro();
	float getYGyro();
	float getZGyro();

	virtual char* getLoRaMessageString();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float xGyro;
	float yGyro;
	float zGyro;

	virtual char* getLoRaMessageId();
};


#endif /* MPU9250GYROSCOPEMESSAGE_H_ */
