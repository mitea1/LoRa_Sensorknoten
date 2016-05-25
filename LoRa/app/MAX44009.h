/*
 * MAX44009.h
 *
 *  Created on: 18.05.2016
 *      Author: Adrian
 */
#include <stdint-gcc.h>
#include <math.h>
#include "I2C_RT.h"
#include "MAX44009Config.h"

#ifndef APP_MAX44009_H_
#define APP_MAX44009_H_

#define MAX44009_ADRESS			0b10010100
#define MAX44009_CONFIG			0x02
#define MAX44009_LUX_H_BYTE		0x03
#define MAX44009_LUX_L_BYTE		0x04
#define MAX44009_LUX_H_L_BYTE	0x0304


class MAX44009 {
public:
	MAX44009(I2C_RT*);
	virtual ~MAX44009();
	void init(MAX44009_MODE);
	double getLux();
private:
	I2C_RT* i2c;
	MAX44009Config* config;
	double calculateLux(uint8_t,uint8_t);

	void setIntegrationTime(uint8_t);
	void setContinousMode(uint8_t);
};

#endif /* APP_MAX44009_H_ */
