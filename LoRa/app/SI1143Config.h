/*
 * SI1143Config.h
 *
 *  Created on: 02.06.2016
 *      Author: Adrian
 */
#include <stdint-gcc.h>

#ifndef APP_SI1143CONFIG_H_
#define APP_SI1143CONFIG_H_

#define SI1143_LED_VOLTAGE_50_MV	0b0001
#define SI1143_LED_VOLTAGE_115_MV	0b0101
#define SI1143_LED_VOLTAGE_185_MV	0b0111
#define SI1143_LED_VOLTAGE_290_MV	0b1010
#define SI1143_LED_VOLTAGE_410_MV	0b1111

enum SI1143_MODE{
	SI1143_MODE_1,
	SI1143_MODE_2,
	SI1143_MODE_3
};

class SI1143Config {
public:
	SI1143Config();
	virtual ~SI1143Config();

	void build(SI1143_MODE);

	uint8_t getLed1Voltage();

private:
	uint8_t led1Voltage;

	void setLed1Voltage(uint8_t);
};

#endif /* APP_SI1143CONFIG_H_ */
