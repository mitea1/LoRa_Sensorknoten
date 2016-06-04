/*
 * MAX44009Config.cpp
 *
 *  Created on: 25.05.2016
 *      Author: Adrian
 */

#include "MAX44009Config.h"

MAX44009Config::MAX44009Config() {
	// TODO Auto-generated constructor stub

}

MAX44009Config::MAX44009Config(MAX44009_MODE desiredMode) {
	build(desiredMode);
}

MAX44009Config::~MAX44009Config() {
	// TODO Auto-generated destructor stub
}

void MAX44009Config::build(MAX44009_MODE desiredMode){
	switch(desiredMode){
		case MAX44009_MODE_1:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_800_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			break;
		case MAX44009_MODE_2:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_400_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			break;
		case MAX44009_MODE_3:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_6_25_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			break;
		default:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_800_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
		}
}

uint8_t MAX44009Config::getIntegrationTime(){
	return this->integrationTime;
}

uint8_t MAX44009Config::getContinousMode(){
	return this->continousMode;
}
void MAX44009Config::setIntegrationTime(uint8_t integrationTime){
	this->integrationTime = integrationTime;
}

void MAX44009Config::setContinousMode(uint8_t continousMode){
	this->continousMode = continousMode;
}
