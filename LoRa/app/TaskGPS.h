/*
 * TaskGPS.h
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */
#include "uBlox.h"
#include "main.h"

#ifndef TASKGPS_H_
#define TASKGPS_H_

class TaskGPS {
public:
	TaskGPS(uBlox*,Mutex*, Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>*);
	TaskGPS(uBlox*,Mutex*,Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskGPS();

	osStatus start(uBLOX_MODE);
	osStatus stop();

private:
	rtos::Thread* thread;
	rtos::Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexUART ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;


	uBlox* mUBlox;
	uBLOX_MODE uBloxMode;

	static void callBack(void const *);
	void measureGps();

	void setQueue(Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setUBLOXMode(uBLOX_MODE);
	uBLOX_MODE getUBLOXMode();
};

#endif /* TASKGPS_H_ */
