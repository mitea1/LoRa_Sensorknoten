/*
 * TaskTemperature.h
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */
#include "BME280.h"
#include "BME280TemperatureMessage.h"
#include "main.h"

#ifndef TASKTEMPERATURE_H_
#define TASKTEMPERATURE_H_

class TaskTemperature {
public:
	TaskTemperature(BME280*,Mutex*, Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>*);
	TaskTemperature(BME280*,Mutex*,Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskTemperature();

	osStatus start(BME280_MODE);
	osStatus stop();

	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	TASK_STATE state;

	BME280* bme280;
	BME280_MODE bme280Mode;

	static void callBack(void const *);
	void measureTemperature();

	void setQueue(Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setBME280Mode(BME280_MODE);
	BME280_MODE getBME280Mode();

	void setState(TASK_STATE);
};

#endif /* TASKTEMPERATURE_H_ */
