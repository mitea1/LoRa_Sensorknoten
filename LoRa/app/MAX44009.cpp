/*
 * MAX44009.cpp
 *
 *  Created on: 18.05.2016
 *      Author: Adrian
 */

#include "MAX44009.h"

MAX44009::MAX44009(I2C_RT* i2c) {
	// TODO Auto-generated constructor stub
	this->i2c = i2c;


}

MAX44009::~MAX44009() {
	// TODO Auto-generated destructor stub
}

double MAX44009::getLux(){
	uint8_t registerData[2];

	i2c->read_RT(MAX44009_ADRESS,MAX44009_LUX_H_L_BYTE,true,registerData,2);

	uint8_t exponent = (registerData[0] >> 4) & 0xF;
	uint8_t mantissa = registerData[0] & 0xF;

	return calculateLux(mantissa,exponent);


}

double MAX44009::calculateLux(uint8_t mantissa, uint8_t exponent){
	return pow(2,exponent) + mantissa * 0.72;
}
