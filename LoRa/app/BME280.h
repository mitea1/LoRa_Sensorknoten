/*
 * BME280.h
 *
 *  Created on: 18.05.2016
 *      Author: Adrian
 */
#include <stdint-gcc.h>
#include "I2C_RT.h"

#ifndef APP_BME280_H_
#define APP_BME280_H_

/*----- Macros -------------------------------------------------------------*/
//Addresses of the BMP280 Sensor
#define BME280_SENSOR_ADDRESS 		0b11101110	/**< Sensor address */
#define BME280_SENSOR_ID			0xD0		/**< ID of BMP280 */
#define BME280_SENSOR_RESET			0xE0		/**< Reset sensor */
#define BME280_SENSOR_CTRL_HUM		0xF2		/**<  */
#define BME280_SENSOR_STATUS		0xF3		/**<  */
#define BME280_SENSOR_CTRL_MEAS		0xF4		/**<  */
#define BME280_SENSOR_CONFIG		0xF5		/**<  */
#define BME280_SENSOR_PRESS_MSB		0xF7		/**< MSB of pressure value */
#define BME280_SENSOR_PRESS_LSB		0xF8		/**< LSB of pressure value */
#define BME280_SENSOR_PRESS_XLSB	0xF9		/**< xtra-LSB of pressure value */
#define BME280_SENSOR_TEMP_MSB		0x00FA		/**< MSB of temperature value */
#define BME280_SENSOR_TEMP_LSB		0x00FB		/**< LSB of temperature value */
#define BME280_SENSOR_TEMP_XLSB		0x00FC		/**< xtra-LSB of temperature value */
#define BME280_SENSOR_HUM_MSB		0xFD		/**< MSB of humidity value */
#define BME280_SENSOR_HUM_LSB		0xFE		/**< xtra-LSB of humidity value */

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

// Trimming Parameters Temperature, Humidity & Pressure
#define BME280_digT1_LSB			0x88		/**< Trimming parameter for temperature */
#define BME280_digT1_MSB			0x89		/**< Trimming parameter for temperature */
#define BME280_digT2_LSB			0x8A		/**< Trimming parameter for temperature */
#define BME280_digT2_MSB			0x8B		/**< Trimming parameter for temperature */
#define BME280_digT3_LSB			0x8C		/**< Trimming parameter for temperature */
#define BME280_digT3_MSB			0x8D		/**< Trimming parameter for temperature */

#define BME280_digP1_LSB			0x8E		/**< Trimming parameter for pressure */
#define BME280_digP1_MSB			0x8F		/**< Trimming parameter for pressure */
#define BME280_digP2_LSB			0x90		/**< Trimming parameter for pressure */
#define BME280_digP2_MSB			0x91		/**< Trimming parameter for pressure */
#define BME280_digP3_LSB			0x92		/**< Trimming parameter for pressure */
#define BME280_digP3_MSB			0x93		/**< Trimming parameter for pressure */
#define BME280_digP4_LSB			0x94		/**< Trimming parameter for pressure */
#define BME280_digP4_MSB			0x95		/**< Trimming parameter for pressure */
#define BME280_digP5_LSB			0x96		/**< Trimming parameter for pressure */
#define BME280_digP5_MSB			0x97		/**< Trimming parameter for pressure */
#define BME280_digP6_LSB			0x98		/**< Trimming parameter for pressure */
#define BME280_digP6_MSB			0x99		/**< Trimming parameter for pressure */
#define BME280_digP7_LSB			0x9A		/**< Trimming parameter for pressure */
#define BME280_digP7_MSB			0x9B		/**< Trimming parameter for pressure */
#define BME280_digP8_LSB			0x9C		/**< Trimming parameter for pressure */
#define BME280_digP8_MSB			0x9D		/**< Trimming parameter for pressure */
#define BME280_digP9_LSB			0x9E		/**< Trimming parameter for pressure */
#define BME280_digP9_MSB			0x9F		/**< Trimming parameter for pressure */

#define BME280_digH1_LSB			0xA1		/**< Trimming parameter for humidity */
#define BME280_digH2_LSB			0xE1		/**< Trimming parameter for humidity */
#define BME280_digH2_MSB			0xE2		/**< Trimming parameter for humidity */
#define BME280_digH3_LSB			0xE3		/**< Trimming parameter for humidity */
#define BME280_digH4_MSB			0xE4		/**< Trimming parameter for humidity */
#define BME280_digH4_LSB			0xE5		/**< Trimming parameter for humidity */
#define BME280_digH5_LSB			0xE6		/**< Trimming parameter for humidity */
#define BME280_digH5_MSB			0xE5		/**< Trimming parameter for humidity */
#define BME280_digH6_LSB			0xE7		/**< Trimming parameter for humidity */

// CTRL_MEAS Settings Modes
#define BME280_SLEEP_MODE			0b00		/**< Sleep mode */
#define BME280_FORCED_MODE			0b01		/**< Forced mode */
#define BME280_NORMAL_MODE			0b11		/**< Normal mode */

//Oversampling Settings
#define BME280_WHEAT_OVRS_T_P		(BME280_TEMP_OVRS_1<<5)|(BME280_PRESS_OVRS_1<<2)|BME280_NORMAL_MODE
#define BME280_WHEAT_OVRS_H			BME280_HUM_OVRS_1

class BME280 {
public:
	BME280(I2C_RT*);
	virtual ~BME280();
	void init();
	void setI2C(I2C_RT*);

	float getHumidityFloat();
	float getPressureFloat();
	float getTemperatureFloat();

private:
	I2C_RT* i2c;

	uint16_t digT1;
	int16_t digT2;
	int16_t digT3;
	uint8_t digH1;
	int16_t digH2;
	uint8_t digH3;
	int16_t digH4;
	int16_t digH5;
	int8_t digH6;
	uint16_t digP1;
	int16_t digP2;
	int16_t digP3;
	int16_t digP4;
	int16_t digP5;
	int16_t digP6;
	int16_t digP7;
	int16_t digP8;
	int16_t digP9;

	int32_t compensateHumidity(int32_t, int32_t);
	int64_t compensatePressure(int32_t, int32_t);
	int32_t compensateTemperature(int32_t);

	void getTrimValuesHumidity();
	void getTrimValuesPressure();
	void getTrimValuesTemperature();

	void setWeatherMonitoringMode();

	uint32_t getHumidity();
	uint32_t getPressure();
	int32_t getTemperature();

};

#endif /* APP_BME280_H_ */
