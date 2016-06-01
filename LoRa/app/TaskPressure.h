/*
 * TaskPressure.h
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */
#include "BME280.h"
#include "BME280PressureMessage.h"
#include "main.h"

#ifndef TASKPRESSURE_H_
#define TASKPRESSURE_H_

class TaskPressure {
public:
	TaskPressure(BME280*,Mutex*, Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>*);
	TaskPressure(BME280*,Mutex*,Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskPressure();

	osStatus start(BME280_MODE);
	osStatus stop();

private:
	rtos::Thread* thread;
	rtos::Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;


	BME280* bme280;
	BME280_MODE bme280Mode;

	static void callBack(void const *);
	void measurePressure();

	void setQueue(Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setBME280Mode(BME280_MODE);
	BME280_MODE getBME280Mode();
};

#endif /* TASKPRESSURE_H_ */
