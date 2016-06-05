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
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(RUNNING);
		max44009Mode = MAX44009_MODE_1;
		bme280Mode = BME280_MODE_1;
		mpu9250Mode = MPU9250_MODE_1;
		si1143Mode = SI1143_MODE_1;
		ubloxMode = uBLOX_MODE_1;
		break;
	case APPLICATION_MODE_2:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		max44009Mode = MAX44009_MODE_1;
		bme280Mode = BME280_MODE_1;
		mpu9250Mode = MPU9250_MODE_1;
		si1143Mode = SI1143_MODE_1;
		ubloxMode = uBLOX_MODE_1;
		break;
	case APPLICATION_MODE_3:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		max44009Mode = MAX44009_MODE_1;
		bme280Mode = BME280_MODE_1;
		mpu9250Mode = MPU9250_MODE_1;
		si1143Mode = SI1143_MODE_1;
		ubloxMode = uBLOX_MODE_1;
		break;
	case APPLICATION_MODE_4:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		max44009Mode = MAX44009_MODE_1;
		bme280Mode = BME280_MODE_1;
		mpu9250Mode = MPU9250_MODE_1;
		si1143Mode = SI1143_MODE_1;
		ubloxMode = uBLOX_MODE_1;
		break;
	case APPLICATION_MODE_5:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	case APPLICATION_MODE_6:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	case APPLICATION_MODE_7:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	case APPLICATION_MODE_8:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	case APPLICATION_MODE_9:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	case APPLICATION_MODE_10:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(RUNNING);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	case APPLICATION_MODE_11:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(SLEEPING);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	case APPLICATION_MODE_99:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		max44009Mode = MAX44009_MODE_3;
		bme280Mode = BME280_MODE_3;
		mpu9250Mode = MPU9250_MODE_3;
		si1143Mode = SI1143_MODE_3;
		ubloxMode = uBLOX_MODE_3;
		break;
	default:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(RUNNING);
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

TASK_STATE ApplicationConfig::getStateTaskLight(){
	return stateTaskLight;
}

TASK_STATE ApplicationConfig::getStateTaskTemperature(){
	return stateTaskTemperature;
}

TASK_STATE ApplicationConfig::getStateTaskPressure(){
	return stateTaskPressure;
}

TASK_STATE ApplicationConfig::getStateTaskHumidity(){
	return stateTaskHumidity;
}

TASK_STATE ApplicationConfig::getStateTaskAcceleration(){
	return stateTaskAcceleration;
}

TASK_STATE ApplicationConfig::getStateTaskGyroscope(){
	return stateTaskGyroscope;
}

TASK_STATE ApplicationConfig::getStateTaskTesla(){
	return stateTaskTesla;
}

TASK_STATE ApplicationConfig::getStateTaskProximity(){
	return stateTaskProximity;
}

TASK_STATE ApplicationConfig::getStateTaskGPS(){
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

void ApplicationConfig::setStateTaskLight(TASK_STATE _stateTaskLight){
	this->stateTaskLight = _stateTaskLight;
}

void ApplicationConfig::setStateTaskTemperature(TASK_STATE _stateTaskTemperature){
	this->stateTaskTemperature = _stateTaskTemperature;
}

void ApplicationConfig::setStateTaskPressure(TASK_STATE _stateTaskPressure){
	this->stateTaskPressure = _stateTaskPressure;
}

void ApplicationConfig::setStateTaskHumidity(TASK_STATE stateTaskHumidity){
	this->stateTaskHumidity = stateTaskHumidity;
}

void ApplicationConfig::setStateTaskAcceleration(TASK_STATE stateTaskAcceleration){
	this->stateTaskAcceleration = stateTaskAcceleration;
}

void ApplicationConfig::setStateTaskGyroscope(TASK_STATE stateTaskGyroscope){
	this->stateTaskGyroscope = stateTaskGyroscope;
}

void ApplicationConfig::setStateTaskTesla(TASK_STATE stateTaskTesla){
	this->stateTaskTesla = stateTaskTesla;
}

void ApplicationConfig::setStateTaskProximity(TASK_STATE stateTaskProximity){
	this->stateTaskProximity = stateTaskProximity;
}

void ApplicationConfig::setStateTaskGPS(TASK_STATE stateTaskGPS){
	this->stateTaskGPS = stateTaskGPS;
}


