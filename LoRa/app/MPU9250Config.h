/*
 * MPU9250Config.h
 *
 *  Created on: 23.05.2016
 *      Author: Adrian
 */

#include <stdint-gcc.h>

#ifndef APP_MPU9250CONFIG_H_
#define APP_MPU9250CONFIG_H_

#define MPU9250_GYRO_FULL_SCALE_250DPS  0b00
#define MPU9250_GYRO_FULL_SCALE_500DPS  0b01
#define MPU9250_GYRO_FULL_SCALE_1000DPS 0b10
#define MPU9250_GYRO_FULL_SCALE_2000DPS 0b11

#define MPU9250_FULL_SCALE_2G           0b00
#define MPU9250_FULL_SCALE_4G           0b01
#define MPU9250_FULL_SCALE_8G           0b10
#define MPU9250_FULL_SCALE_16G          0b11

enum MPU9250_MODE{
	MPU9250_MODE_1,
	MPU9250_MODE_2,
	MPU9250_MODE_3
};

class MPU9250Config {
public:
	MPU9250Config();
	virtual ~MPU9250Config();
	void build(MPU9250_MODE);

	uint8_t getAccelerometerScale();
	uint8_t getGyroscopeScale();
	float getAccelerationDivider();
	float getGyroDivider();

private:
	uint8_t gyroscopeScale;
	uint8_t accelerometerScale;

	void setAccelerometerScale(uint8_t);
	void setGyroscopeScale(uint8_t);
};

#endif /* APP_MPU9250CONFIG_H_ */
