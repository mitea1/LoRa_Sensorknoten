/*
 * MPU9250TeslaMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */
#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

#ifndef MPU9250TESLAMESSAGE_H_
#define MPU9250TESLAMESSAGE_H_

#define MPU9250_X_TESLA_MESSAGE_ID		"M7"
#define MPU9250_Y_TESLA_MESSAGE_ID		"M8"
#define MPU9250_Z_TESLA_MESSAGE_ID		"M9"

class MPU9250TeslaMessage: public SensorMessage {
public:
	MPU9250TeslaMessage();
	virtual ~MPU9250TeslaMessage();

	void setXTesla(float);
	void setYTesla(float);
	void setZTesla(float);

	float getXTesla();
	float getYTesla();
	float getZTesla();

	virtual char* getLoRaMessageString();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float xTesla;
	float yTesla;
	float zTesla;

	virtual char* getLoRaMessageId();
};


#endif /* MPU9250TESLAMESSAGE_H_ */
