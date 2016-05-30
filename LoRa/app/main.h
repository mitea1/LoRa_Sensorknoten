/*
 * main.h
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */
#include <Queue.h>
#include "BME280.h"
#include "MAX44009.h"
#include "MPU9250.h"

#ifndef MAIN_H_
#define MAIN_H_


#define LIGHT_QUEUE_LENGHT			1
#define ACCELERATION_QUEUE_LENGHT	1
#define GYROSCOPE_QUEUE_LENGHT		1
#define TESLA_QUEUE_LENGHT			1
#define TEMPERATURE_QUEUE_LENGHT	1
#define PRESSURE_QUEUE_LENGHT		1
#define HUMIDITY_QUEUE_LENGHT		1

#define LIGHT_TASK_DELAY_MS 100
#define DATAHANLDER_TASK_DELAY_MS 500

typedef struct QueueBundle{
	Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queueLight;
	Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queueTemperature;
	Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queuePressure;
	Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queueHumidity;
	Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queueAcceleration;
	Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queueGyro;
	Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queueTesla;
};


#endif /* MAIN_H_ */
