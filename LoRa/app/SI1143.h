/*
 * SI1143.h
 *
 *  Created on: 18.05.2016
 *      Author: Adrian
 */
#include "I2C_RT.h"

#ifndef APP_SI1143_H_
#define APP_SI1143_H_

class SI1143 {
public:
	SI1143(I2C_RT*);
	virtual ~SI1143();
	void init();

private:
	I2C_RT* i2c;

	void setI2C(I2C_RT*);
};

#endif /* APP_SI1143_H_ */
