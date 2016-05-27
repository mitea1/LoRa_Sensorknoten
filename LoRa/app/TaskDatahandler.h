/*
 * TaskDatahandler.h
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#ifndef TASKDATAHANDLER_H_
#define TASKDATAHANDLER_H_

#include <Thread.h>
#include <Queue.h>
#include <Mutex.h>
#include <mDot.h>
#include "MAX44009.h"
#include "main.h"

class TaskDatahandler {
public:
	TaskDatahandler(Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskDatahandler();

	osStatus start();

	void setDebugSerial(RawSerial*);
private:
	Thread* thread;
	Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queueLight;
	RawSerial* debugSerial;

	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	static void callBack(void const *);
	void handleData();

	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);
};

#endif /* TASKDATAHANDLER_H_ */
