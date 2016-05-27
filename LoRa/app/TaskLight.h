/*
 * TaskLight.h
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#ifndef TASKLIGHT_H_
#define TASKLIGHT_H_

#include <Thread.h>
#include <Queue.h>
#include <Mutex.h>
#include "MAX44009.h"
#include "main.h"

class TaskLight{
public:
	TaskLight(MAX44009*,Mutex*, Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>*);
	TaskLight(MAX44009*,Mutex*,Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskLight();

	osStatus start();

private:
	rtos::Thread* thread;
	rtos::Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;


	MAX44009* max44009;

	static void callBack(void const *);
	void measureLight();

	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

};
#endif /* TASKLIGHT_H_ */
