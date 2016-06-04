/*
 * SensorHandler.cpp
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */

#include "SensorHandler.h"

SensorHandler::SensorHandler() {
	initInterfaces();
	initSensors();
	initMutexes();
	initTasks();
	initApplicationConfig();
	taskDataHandler->start();
}

SensorHandler::~SensorHandler() {
	delete uart;
	delete debugSerial;
	delete i2c_rt;

	delete gpsSensor;
	delete max44009;
	delete bme280;
	delete mpu9250;
	delete si1143;

	delete taskLight;
	delete taskTemperature;
	delete taskPressure;
	delete taskHumidity;
	delete taskAcceleration;
	delete taskGyroscope;
	delete taskTesla;
	delete taskProximity;
	delete taskGps;
}

void SensorHandler::init(APPLICATION_MODE desiredMode){
	config->build(desiredMode);
	stopAllRunningSensorTasks();
	startRunnableSensorTasks();
}

void SensorHandler::stopAllRunningSensorTasks(){
	if(taskLight->getState() == ApplicationConfig::RUNNING_STATE){
		taskLight->stop();
	}
	if(taskTemperature->getState() == ApplicationConfig::RUNNING_STATE){
		taskTemperature->stop();
	}
	if(taskPressure->getState() == ApplicationConfig::RUNNING_STATE){
		taskPressure->stop();
	}
	if(taskHumidity->getState() == ApplicationConfig::RUNNING_STATE){
		taskHumidity->stop();
	}
	if(taskAcceleration->getState() == ApplicationConfig::RUNNING_STATE){
		taskAcceleration->stop();
	}
	if(taskGyroscope->getState() == ApplicationConfig::RUNNING_STATE){
		taskGyroscope->stop();
	}
	if(taskTesla->getState() == ApplicationConfig::RUNNING_STATE){
		taskTesla->stop();
	}
	if(taskProximity->getState() == ApplicationConfig::RUNNING_STATE){
		taskProximity->stop();
	}
	if(taskGps->getState() == ApplicationConfig::RUNNING_STATE){
		taskGps->stop();
	}
}

void SensorHandler::initInterfaces(){
	uart = new RawSerial(XBEE_DOUT,XBEE_DIN);
	debugSerial = new RawSerial(USBTX,USBRX);
	i2c_rt = new I2C_RT();
	dot = mDot::getInstance();
	lora = new LoRa(dot,debugSerial);

	uart->baud(BAUD_UART);
	uart->format(8,SerialBase::None,1);
	debugSerial->baud(BAUD_USB);
	debugSerial->format(8,SerialBase::None,1);
}

void SensorHandler::initSensors(){
	gpsSensor = new uBlox(uart);
	max44009 = new MAX44009(i2c_rt);
	bme280 = new BME280(i2c_rt);
	mpu9250 = new MPU9250(i2c_rt);
	si1143 = new SI1143(i2c_rt);
}

void SensorHandler::initTasks(){
	taskLight = new TaskLight(max44009,mutexI2C,&queueLight,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskTemperature = new TaskTemperature(bme280,mutexI2C,&queueTemperature,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskHumidity = new  TaskHumidity(bme280,mutexI2C,&queueHumidity,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskPressure = new  TaskPressure(bme280,mutexI2C,&queuePressure,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskAcceleration = new  TaskAcceleration(mpu9250,mutexI2C,&queueAcceleration,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskGyroscope = new  TaskGyroscope(mpu9250,mutexI2C,&queueGyro,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskTesla = new  TaskTesla(mpu9250,mutexI2C,&queueTesla,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskProximity = new  TaskProximity(si1143,mutexI2C,&queueProximity,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskGps = new  TaskGPS(gpsSensor,mutexUART1,&queueGps,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskDataHandler = new  TaskDatahandler(lora,queueBundle,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	taskDataHandler->setDebugSerial(debugSerial);
}

void SensorHandler::startRunnableSensorTasks(){
	if(config->getStateTaskLight() == ApplicationConfig::RUNNING_STATE){
		taskLight->start(config->getMAX44009_MODE());
	}
	if(config->getStateTaskTemperature() == ApplicationConfig::RUNNING_STATE){
		taskTemperature->start(config->getBME280_MODE());
	}
	if(config->getStateTaskPressure() == ApplicationConfig::RUNNING_STATE){
		taskPressure->start(config->getBME280_MODE());
	}
	if(config->getStateTaskHumidity() == ApplicationConfig::RUNNING_STATE){
		taskHumidity->start(config->getBME280_MODE());
	}
	if(config->getStateTaskAcceleration() == ApplicationConfig::RUNNING_STATE){
		taskAcceleration->start(config->getMPU9250_MODE());
	}
	if(config->getStateTaskGyroscope() == ApplicationConfig::RUNNING_STATE){
		taskGyroscope->start(config->getMPU9250_MODE());
	}
	if(config->getStateTaskTesla() == ApplicationConfig::RUNNING_STATE){
		taskTesla->start(config->getMPU9250_MODE());
	}
	if(config->getStateTaskProximity() == ApplicationConfig::RUNNING_STATE){
		//taskProximity->start(config->getSI1143_MODE());
	}
	if(config->getStateTaskGPS() == ApplicationConfig::RUNNING_STATE){
		taskGps->start(config->getuBlox_MODE());
	}
}

void SensorHandler::initMutexes(){
	this->mutexI2C = new Mutex();
	this->mutexUART1 = new Mutex();
}

void SensorHandler::initApplicationConfig(){
	config = new ApplicationConfig();
}
