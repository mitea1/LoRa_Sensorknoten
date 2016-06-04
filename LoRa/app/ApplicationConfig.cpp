/*
 * Application_MODE.cpp
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */

#include "ApplicationConfig.h"

ApplicationConfig::ApplicationConfig() {
	// TODO Auto-generated constructor stub

}

ApplicationConfig::~ApplicationConfig() {
	// TODO Auto-generated destructor stub
}

void ApplicationConfig::build(APPLICATION_MODE desiredMode) {
	switch (desiredMode) {
	case APPLICATION_MODE_1:
		setStateTaskLight(RUNNING_STATE);
		setStateTaskTemperature(RUNNING_STATE);
		setStateTaskPressure(RUNNING_STATE);
		setStateTaskHumidity(RUNNING_STATE);
		setStateTaskAcceleration(RUNNING_STATE);
		setStateTaskGyroscope(RUNNING_STATE);
		setStateTaskTesla(RUNNING_STATE);
		setStateTaskProximity(RUNNING_STATE);
		setStateTaskGPS(RUNNING_STATE);
		max44009Mode = MAX44009_MODE_1;
		bme280Mode = BME280_MODE_1;
		mpu9250Mode = MPU9250_MODE_1;
		si1143Mode = SI1143_MODE_1;
		ubloxMode = uBLOX_MODE_1;
		break;
	case APPLICATION_MODE_2:
		setStateTaskLight(SLEEPING_STATE);
		setStateTaskTemperature(RUNNING_STATE);
		setStateTaskPressure(RUNNING_STATE);
		setStateTaskHumidity(RUNNING_STATE);
		setStateTaskAcceleration(SLEEPING_STATE);
		setStateTaskGyroscope(SLEEPING_STATE);
		setStateTaskTesla(SLEEPING_STATE);
		setStateTaskProximity(SLEEPING_STATE);
		setStateTaskGPS(RUNNING_STATE);
		max44009Mode = MAX44009_MODE_2;
		bme280Mode = BME280_MODE_2;
		mpu9250Mode = MPU9250_MODE_2;
		si1143Mode = SI1143_MODE_2;
		ubloxMode = uBLOX_MODE_2;
		break;
	case APPLICATION_MODE_3:
		setStateTaskLight(SLEEPING_STATE);
		setStateTaskTemperature(RUNNING_STATE);
		setStateTaskPressure(RUNNING_STATE);
		setStateTaskHumidity(RUNNING_STATE);
		setStateTaskAcceleration(SLEEPING_STATE);
		setStateTaskGyroscope(SLEEPING_STATE);
		setStateTaskTesla(SLEEPING_STATE);
		setStateTaskProximity(SLEEPING_STATE);
		setStateTaskGPS(RUNNING_STATE);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	}
}

MAX44009_MODE ApplicationConfig::getMAX44009_MODE() {
	return max44009Mode;
}

BME280_MODE ApplicationConfig::getBME280_MODE() {
	return bme280Mode;
}

MPU9250_MODE ApplicationConfig::getMPU9250_MODE() {
	return mpu9250Mode;
}

SI1143_MODE ApplicationConfig::getSI1143_MODE() {
	return si1143Mode;
}

uBLOX_MODE ApplicationConfig::getuBlox_MODE() {
	return ubloxMode;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskLight(){
	return stateTaskLight;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskTemperature(){
	return stateTaskTemperature;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskPressure(){
	return stateTaskPressure;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskHumidity(){
	return stateTaskHumidity;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskAcceleration(){
	return stateTaskAcceleration;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskGyroscope(){
	return stateTaskGyroscope;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskTesla(){
	return stateTaskTesla;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskProximity(){
	return stateTaskProximity;
}

ApplicationConfig::TASK_STATE ApplicationConfig::getStateTaskGPS(){
	return stateTaskGPS;
}

void ApplicationConfig::setMAX44009_MODE(MAX44009_MODE max44009Mode) {
	this->max44009Mode = max44009Mode;
}

void ApplicationConfig::setBME280_MODE(BME280_MODE bme280Mode) {
	this->bme280Mode = bme280Mode;
}

void ApplicationConfig::setMPU9250_MODE(MPU9250_MODE mpu9250Mode) {
	this->mpu9250Mode = mpu9250Mode;
}

void ApplicationConfig::setSI1143_MODE(SI1143_MODE si1143Mode) {
	this->si1143Mode = si1143Mode;
}

void ApplicationConfig::setuBlox_MODE(uBLOX_MODE ubloxMode) {
	this->ubloxMode = ubloxMode;
}

void ApplicationConfig::setStateTaskLight(ApplicationConfig::TASK_STATE _stateTaskLight){
	this->stateTaskLight = _stateTaskLight;
}

void ApplicationConfig::setStateTaskTemperature(ApplicationConfig::TASK_STATE _stateTaskTemperature){
	this->stateTaskTemperature = _stateTaskTemperature;
}

void ApplicationConfig::setStateTaskPressure(ApplicationConfig::TASK_STATE _stateTaskPressure){
	this->stateTaskPressure = _stateTaskPressure;
}

void ApplicationConfig::setStateTaskHumidity(ApplicationConfig::TASK_STATE stateTaskHumidity){
	this->stateTaskHumidity = stateTaskHumidity;
}

void ApplicationConfig::setStateTaskAcceleration(ApplicationConfig::TASK_STATE stateTaskAcceleration){
	this->stateTaskAcceleration = stateTaskAcceleration;
}

void ApplicationConfig::setStateTaskGyroscope(ApplicationConfig::TASK_STATE stateTaskGyroscope){
	this->stateTaskGyroscope = stateTaskGyroscope;
}

void ApplicationConfig::setStateTaskTesla(ApplicationConfig::TASK_STATE stateTaskTesla){
	this->stateTaskTesla = stateTaskTesla;
}

void ApplicationConfig::setStateTaskProximity(ApplicationConfig::TASK_STATE stateTaskProximity){
	this->stateTaskProximity = stateTaskProximity;
}

void ApplicationConfig::setStateTaskGPS(ApplicationConfig::TASK_STATE stateTaskGPS){
	this->stateTaskGPS = stateTaskGPS;
}


