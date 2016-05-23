/*
 * SI1143.cpp
 *
 *  Created on: 18.05.2016
 *      Author: Adrian
 */

#include "SI1143.h"

SI1143::SI1143(I2C_RT* i2c) {
	setI2C(i2c);
}

SI1143::~SI1143() {
	// TODO Auto-generated destructor stub
}

void SI1143::init(){

}

void SI1143::setI2C(I2C_RT* i2c){
	this->i2c = i2c;
}

