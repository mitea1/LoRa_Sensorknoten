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
	configureSensors();
	configureLora();
	startRunnableSensorTasks();
}

void SensorHandler::stopAllRunningSensorTasks(){
	if(taskLight->getState() == RUNNING){
		taskLight->stop();
	}
	if(taskTemperature->getState() == RUNNING){
		taskTemperature->stop();
	}
	if(taskPressure->getState() == RUNNING){
		taskPressure->stop();
	}
	if(taskHumidity->getState() == RUNNING){
		taskHumidity->stop();
	}
	if(taskAcceleration->getState() == RUNNING){
		taskAcceleration->stop();
	}
	if(taskGyroscope->getState() == RUNNING){
		taskGyroscope->stop();
	}
	if(taskTesla->getState() == RUNNING){
		taskTesla->stop();
	}
	if(taskProximity->getState() == RUNNING){
		taskProximity->stop();
	}
	if(taskGps->getState() == RUNNING){
		taskGps->stop();
	}

	osDelay(100);
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
	if(config->getStateTaskLight() == RUNNING){
		taskLight->start();
	}
	if(config->getStateTaskTemperature() == RUNNING){
		taskTemperature->start();
	}
	if(config->getStateTaskPressure() == RUNNING){
		taskPressure->start();
	}
	if(config->getStateTaskHumidity() == RUNNING){
		taskHumidity->start();
	}
	if(config->getStateTaskAcceleration() == RUNNING){
		taskAcceleration->start();
	}
	if(config->getStateTaskGyroscope() == RUNNING){
		taskGyroscope->start();
	}
	if(config->getStateTaskTesla() == RUNNING){
		taskTesla->start();
	}
	if(config->getStateTaskProximity() == RUNNING){
		taskProximity->start();
	}
	if(config->getStateTaskGPS() == RUNNING){
		taskGps->start();
	}
}

void SensorHandler::configureSensors(){
	max44009->init(config->getMAX44009_MODE());
	bme280->init(config->getBME280_MODE());
	mpu9250->init(config->getMPU9250_MODE());
	si1143->init(config->getSI1143_MODE());
	gpsSensor->init(config->getuBlox_MODE());
}

void SensorHandler::configureLora(){
	lora->init(config->getLORA_MODE());
}

void SensorHandler::initMutexes(){
	this->mutexI2C = new Mutex();
	this->mutexUART1 = new Mutex();
}

void SensorHandler::initApplicationConfig(){
	config = new ApplicationConfig();
}
