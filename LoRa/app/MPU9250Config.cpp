/*
 * MPU9250Config.cpp
 *
 *  Created on: 23.05.2016
 *      Author: Adrian
 */

#include "MPU9250Config.h"

MPU9250Config::MPU9250Config() {
	// TODO Auto-generated constructor stub

}

MPU9250Config::~MPU9250Config() {
	// TODO Auto-generated destructor stub
}

void MPU9250Config::build(MPU9250_MODE desiredMode){
	switch(desiredMode){
	case MODE_1:
		setAccelerometerScale(MPU9250_FULL_SCALE_2G);
		setGyroscopeScale(MPU9250_GYRO_FULL_SCALE_250DPS);
		break;
	case MODE_2:
		setAccelerometerScale(MPU9250_FULL_SCALE_4G);
		setGyroscopeScale(MPU9250_GYRO_FULL_SCALE_500DPS);
		break;
	case MODE_3:
		setAccelerometerScale(MPU9250_FULL_SCALE_8G);
		setGyroscopeScale(MPU9250_GYRO_FULL_SCALE_1000DPS);
		break;
	}
}

void MPU9250Config::setAccelerometerScale(uint8_t accelerometerScale){
	this->accelerometerScale = accelerometerScale;
}

void MPU9250Config::setGyroscopeScale(uint8_t gyroscopeScale){
	this->gyroscopeScale = gyroscopeScale;
}

uint8_t MPU9250Config::getAccelerometerScale(){
	return this->accelerometerScale;
}

uint8_t MPU9250Config::getGyroscopeScale(){
	return this->gyroscopeScale;
}

float MPU9250Config::getAccelerationDivider(){
	float divider;

	switch(accelerometerScale){
		case MPU9250_FULL_SCALE_2G:
			divider = 32768/2;
			break;
		case MPU9250_FULL_SCALE_4G:
			divider = 32768/4;
			break;
		case MPU9250_FULL_SCALE_8G:
			divider = 32768/8;
			break;
		case MPU9250_FULL_SCALE_16G:
			divider = 32768/16;
			break;
		default:
			divider = 1;
			break;
	}

	return divider;
}

float MPU9250Config::getGyroDivider(){
	float divider;

	switch(accelerometerScale){
		case MPU9250_GYRO_FULL_SCALE_250DPS:
			divider = 32768/250;
			break;
		case MPU9250_GYRO_FULL_SCALE_500DPS:
			divider = 32768/500;
			break;
		case MPU9250_GYRO_FULL_SCALE_1000DPS:
			divider = 32768/1000;
			break;
		case MPU9250_GYRO_FULL_SCALE_2000DPS:
			divider = 32768/2000;
			break;
		default:
			divider = 1;
			break;
	}

	return divider;
}



