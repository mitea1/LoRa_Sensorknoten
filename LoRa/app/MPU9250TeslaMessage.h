/*
 * MPU9250TeslaMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef MPU9250TESLAMESSAGE_H_
#define MPU9250TESLAMESSAGE_H_

#include "SensorMessage.h"

class MPU9250TeslaMessage: public SensorMessage {
public:
	MPU9250TeslaMessage();
	virtual ~MPU9250TeslaMessage();

	void setXTesla();
	void setYTesla();
	void setZTesla();

	float getXTesla();
	float getYTesla();
	float getZTesla();

private:
	char loraMessage[20];
	char loraMessageId[2];

	float xTesla;
	float yTesla;
	float zTesla;
};


#endif /* MPU9250TESLAMESSAGE_H_ */
