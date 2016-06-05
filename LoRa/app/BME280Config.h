/*
 * BME280Config.h
 *
 *  Created on: 24.05.2016
 *      Author: Adrian
 */
#include <stdint-gcc.h>

#ifndef APP_BME280CONFIG_H_
#define APP_BME280CONFIG_H_

// CTRL_HUM  Humidity over sampling Settings
#define BME280_HUM_SKPPD			0b000
#define BME280_HUM_OVRS_1			0b001
#define BME280_HUM_OVRS_2			0b010
#define BME280_HUM_OVRS_4			0b011
#define BME280_HUM_OVRS_8			0b100
#define BME280_HUM_OVRS_16			0b101

// CTRL_HUM  Pressure over sampling Settings
#define BME280_PRESS_SKPPD			0b000
#define BME280_PRESS_OVRS_1			0b001
#define BME280_PRESS_OVRS_2			0b010
#define BME280_PRESS_OVRS_4			0b011
#define BME280_PRESS_OVRS_8			0b100
#define BME280_PRESS_OVRS_16		0b101

// CTRL_HUM  Temperature over sampling Settings
#define BME280_TEMP_SKPPD			0b000
#define BME280_TEMP_OVRS_1			0b001
#define BME280_TEMP_OVRS_2			0b010
#define BME280_TEMP_OVRS_4			0b011
#define BME280_TEMP_OVRS_8			0b100
#define BME280_TEMP_OVRS_16			0b101

// CTRL_MEAS Settings Modes
#define BME280_SLEEP_MODE			0b00		/**< Sleep mode */
#define BME280_FORCED_MODE			0b01		/**< Forced mode */
#define BME280_NORMAL_MODE			0b11		/**< Normal mode */

//Oversampling Settings
#define BME280_WHEAT_OVRS_T_P		(BME280_TEMP_OVRS_1<<5)|(BME280_PRESS_OVRS_1<<2)|BME280_NORMAL_MODE
#define BME280_WHEAT_OVRS_H			BME280_HUM_OVRS_1


enum BME280_MODE{
	BME280_MODE_0,
	BME280_MODE_1,
	BME280_MODE_2,
	BME280_MODE_3,
	BME280_MODE_4,
	BME280_MODE_5,
	BME280_MODE_6,
	BME280_MODE_7,
	BME280_MODE_8,
	BME280_MODE_9,
};

class BME280Config {
public:
	BME280Config();
	virtual ~BME280Config();
	void build(BME280_MODE);

	uint8_t getOversamplingTemperature();
	uint8_t getOversamplingPressure();
	uint8_t getOversamplingHumidity();

	uint8_t getMode();

private:
	uint8_t oversamplingTemperature;
	uint8_t oversamplingPressure;
	uint8_t oversamplingHumidity;

	uint8_t mode;


	void setOversamplingTemperature(uint8_t);
	void setOversamplingPressure(uint8_t);
	void setOversamplingHumidity(uint8_t);

	void setMode(uint8_t);
};

#endif /* APP_BME280CONFIG_H_ */
