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

#define SI1143_PS1_IRQ_EN_MASK		0x02
#define SI1143_THRESHOLD_1000		0x3E8


enum SI1143_MODE{
	SI1143_MODE_1,
	SI1143_MODE_2,
	SI1143_MODE_3,
	SI1143_MODE_4
};

class SI1143Config {
public:
	SI1143Config();
	virtual ~SI1143Config();

	void build(SI1143_MODE);

	uint8_t getLed1Voltage();
	uint8_t getInterruptEnable();
	uint8_t getProximitySensing1Threshold();

private:
	uint8_t led1Voltage;
	uint8_t interruptEnable;
	uint16_t proximitySensing1Threshold;

	void setLed1Voltage(uint8_t);
	void setInterruptEnable(uint8_t);
	void setProximitySensing1Threshold(uint16_t);
};

#endif /* APP_SI1143CONFIG_H_ */
