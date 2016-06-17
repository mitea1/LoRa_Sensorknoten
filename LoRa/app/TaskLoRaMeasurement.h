/*
 * TaskLoRaMeasurement.h
 *
 *  Created on: 13.06.2016
 *      Author: Adrian
 */

#include <Thread.h>
#include <Queue.h>
#include <Mutex.h>
#include "LoRa.h"
#include "LoRaMeasuermentMessage.h"
#include "main.h"

#ifndef APP_TASKLORAMEASUREMENT_H_
#define APP_TASKLORAMEASUREMENT_H_

class TaskLoRaMeasurement {
public:
	TaskLoRaMeasurement(LoRa*,Mutex*, Queue<LoRaMeasuermentMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*);
	TaskLoRaMeasurement(LoRa*,Mutex*,Queue<LoRaMeasuermentMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskLoRaMeasurement();

	osStatus start();
	osStatus stop();

	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<LoRaMeasuermentMessage,LORA_MEASUREMENT_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexLoRa ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	TASK_STATE state;

	LoRa* lora;

	static void callBack(void const *);
	void measureSignal();

	void setQueue(Queue<LoRaMeasuermentMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setState(TASK_STATE);

};

#endif /* APP_TASKLORAMEASUREMENT_H_ */
