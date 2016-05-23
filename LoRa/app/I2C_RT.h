/*
 * I2C_RT.h
 *
 *  Created on: 19.05.2016
 *      Author: Adrian
 */

#ifndef APP_I2C_RT_H_
#define APP_I2C_RT_H_

#include <I2C.h>
#include <rtos.h>

class I2C_RT{
public:
	I2C_RT();
	virtual ~I2C_RT();
	void read_RT(uint8_t,uint16_t,bool,uint8_t*,uint8_t);
	void write_RT(uint8_t,uint16_t,bool,uint8_t*,uint8_t);
	void setMbedI2C(mbed::I2C*);

private:



};

#endif /* APP_I2C_RT_H_ */
