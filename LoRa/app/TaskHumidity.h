/*
 * TaskHumidity.h
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */
#include "BME280.h"
#include "BME280HumidityMessage.h"
#include "main.h"

#ifndef TASKHUMIDITY_H_
#define TASKHUMIDITY_H_

class TaskHumidity {

public:
	TaskHumidity(BME280*,Mutex*, Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>*);
	TaskHumidity(BME280*,Mutex*,Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskHumidity();

	osStatus start();
	osStatus stop();

	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	TASK_STATE state;

	BME280* bme280;
	BME280_MODE bme280Mode;

	static void callBack(void const *);
	void measureHumidity();

	void setQueue(Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setState(TASK_STATE);
};


#endif /* TASKHUMIDITY_H_ */
