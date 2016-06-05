/*
 * SensorHandler.h
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */
#include "ApplicationConfig.h"
#include "mbed.h"
#include "rtos.h"
#include "I2C_RT.h"
#include "MAX44009.h"
#include "BME280.h"
#include "MPU9250.h"
#include "SI1143.h"
#include "uBlox.h"
#include "mDot.h"
#include "LoRa.h"
#include "TaskLight.h"
#include "TaskTemperature.h"
#include "TaskHumidity.h"
#include "TaskPressure.h"
#include "TaskAcceleration.h"
#include "TaskGyroscope.h"
#include "TaskTesla.h"
#include "TaskProximity.h"
#include "TaskGPS.h"
#include "TaskDatahandler.h"
#include "main.h"

#ifndef SENSORHANDLER_H_
#define SENSORHANDLER_H_

class SensorHandler {
public:
	SensorHandler();
	virtual ~SensorHandler();

	void init(APPLICATION_MODE);

private:
	RawSerial* uart;
	RawSerial* debugSerial;
	I2C_RT* i2c_rt;
	mDot* dot;
	LoRa* lora;

	TaskLight* taskLight;
	TaskTemperature* taskTemperature;
	TaskPressure* taskPressure;
	TaskHumidity* taskHumidity;
	TaskAcceleration* taskAcceleration;
	TaskGyroscope* taskGyroscope;
	TaskTesla* taskTesla;
	TaskProximity* taskProximity;
	TaskGPS* taskGps;
	TaskDatahandler* taskDataHandler;

	rtos::Mutex* mutexI2C;
	rtos::Mutex* mutexUART1;
	rtos::Mutex mutexBME280;
	rtos::Mutex mutexMAX44009;
	rtos::Mutex mutexMPU9250;
	rtos::Mutex mutexSi4103;
	rtos::Mutex mutexUBlox;

	Queue<MAX44009Message,LIGHT_QUEUE_LENGHT> queueLight;
	Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT> queueTemperature;
	Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT> queuePressure;
	Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT> queueHumidity;
	Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT> queueAcceleration;
	Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT> queueGyro;
	Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT> queueTesla;
	Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT> queueProximity;
	Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT> queueGps;

	QueueBundle queueBundle = {&queueLight,&queueTemperature,&queuePressure,&queueHumidity,
								&queueAcceleration,&queueGyro,&queueTesla,&queueProximity,&queueGps};

	uBlox* gpsSensor;
	MAX44009* max44009;
	BME280*	bme280;
	MPU9250* mpu9250;
	SI1143* si1143;

	ApplicationConfig* config;

	void initInterfaces();
	void initSensors();
	void initTasks();
	void initMutexes();
	void initApplicationConfig();


	void stopAllRunningSensorTasks();
	void startRunnableSensorTasks();

};

#endif /* SENSORHANDLER_H_ */
