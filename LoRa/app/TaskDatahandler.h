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
#include "LoRa.h"
#include "MAX44009Message.h"
#include "BME280TemperatureMessage.h"
#include "BME280PressureMessage.h"
#include "BME280HumidityMessage.h"
#include "CommandMessage.h"
#include "main.h"


class TaskDatahandler {
public:
	TaskDatahandler(LoRa*,Mutex*,QueueBundle,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskDatahandler();

	osStatus start();
	osStatus stop();

	TASK_STATE getState();

	void setDebugSerial(RawSerial*);
	void setLoRa(LoRa* lora);

private:
	Thread* thread;
	QueueBundle queueBundle;
	RawSerial* debugSerial;
	LoRa* lora;
	Mutex* mutexLora;

	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	TASK_STATE state;

	osEvent lightMeasureEvent;
	osEvent temperatureMeasureEvent;
	osEvent pressureMeasureEvent;
	osEvent humidityMeasureEvent;
	osEvent accelerationMeasureEvent;
	osEvent gyroscopeMeasureEvent;
	osEvent teslaMeasureEvent;
	osEvent proximityMeasureEvent;
	osEvent gpsMeasureEvent;
	osEvent loraMeasureEvent;

	static void callBack(void const *);
	void handleData();
	void getMessagesFromSensorQueues();
	void forwardSensorMessages();

	void setMutex(Mutex*);
	void setQueueBundle(QueueBundle);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setState(TASK_STATE);

};

#endif /* TASKDATAHANDLER_H_ */
