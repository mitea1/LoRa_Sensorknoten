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
	TaskDatahandler(QueueBundle,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskDatahandler();

	osStatus start();

	void setDebugSerial(RawSerial*);
private:
	Thread* thread;
	QueueBundle queueBundle;
	RawSerial* debugSerial;

	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	osEvent lightMeasureEvent;
	osEvent temperatureMeasureEvent;
	osEvent pressureMeasureEvent;
	osEvent humidityMeasureEvent;
	osEvent accelerationMeasureEvent;
	osEvent gyroscopeMeasureEvent;
	osEvent teslaMeasureEvent;

	static void callBack(void const *);
	void handleData();
	void getMessagesFromSensorQueues();
	void forwardSensorMessages();

	void setQueueBundle(QueueBundle);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);



};

#endif /* TASKDATAHANDLER_H_ */
