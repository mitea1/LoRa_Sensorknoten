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

#define MPU9250_MAG_16_BIT				0b1
#define MPU9250_MAG_14_BIT				0b0

#define MPU9250_MAG_SINGLE_MEASUREMENT			0b0001
#define MPU9250_MAG_CONTINUOUS_MEASUREMENT_1	0b0010
#define MPU9250_MAG_CONTINUOUS_MEASUREMENT_2	0b0110

//INT_PIN_CFG register masks
#define MPU9250_ACTL_MASK               0x80
#define MPU9250_OPEN_MASK               0x40
#define MPU9250_LATCH_INT_EN_MASK       0x20
#define MPU9250_INT_ANYRD_2CLEAR_MASK   0x10
#define MPU9250_ACTL_FSYNC_MASK         0x08
#define MPU9250_FSYNC_INT_MODE_EN_MASK  0x04
#define MPU9250_BYPASS_EN_MASK          0x02

//INT_ENABLE register masks
#define MPU9250_WOM_EN_MASK             0x40
#define MPU9250_FIFO_OFLOW_EN_MASK      0x10
#define MPU9250_FSYNC_INT_EN_MASK       0x08
#define MPU9250_RAW_RDY_EN_MASK         0x01

#define MPU9250_WOM_THRESHOLD_1020_MG	0xFF
#define MPU9250_WOM_THRESHOLD_500_MG	0x7D
#define MPU9250_WOM_THRESHOLD_250_MG	0xFA

enum MPU9250_MODE{
	MPU9250_MODE_1,
	MPU9250_MODE_2,
	MPU9250_MODE_3,
	MPU9250_MODE_4
};

class MPU9250Config {
public:
	MPU9250Config();
	virtual ~MPU9250Config();
	void build(MPU9250_MODE);

	uint8_t getAccelerometerScale();
	uint8_t getGyroscopeScale();
	uint8_t getMagnetometerBitResolution();
	uint8_t getMagnetometerMeasureMode();
	float getAccelerationDivider();
	float getGyroDivider();
	float getTeslaDivider();

	uint8_t getInterruptPinConfiguration();
	uint8_t getInterruptEnableConfiguration();

	uint8_t getWakeOnMotionThreshold();

private:
	uint8_t gyroscopeScale;
	uint8_t accelerometerScale;
	uint8_t magnetometerBitResolution;
	uint8_t magnetometerMeasureMode;

	uint8_t interruptPinConfiguration;
	uint8_t interruptEnableConfiguration;

	uint8_t wakeOnMotionThreshold;

	void setAccelerometerScale(uint8_t);
	void setGyroscopeScale(uint8_t);
	void setMagnetometerBitResolution(uint8_t);
	void setMagnetometerMeasureMode(uint8_t);

	void setInterruptPinConfiguration(uint8_t);
	void setInterruptEnableConfiguration(uint8_t);

	void setWakeOnMotionThreshold(uint8_t);
};

#endif /* APP_MPU9250CONFIG_H_ */
