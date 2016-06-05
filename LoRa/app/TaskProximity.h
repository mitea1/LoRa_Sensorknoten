/*
 * TaskProximity.h
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */
#include "SI1143.h"
#include "SI1143ProximityMessage.h"
#include "main.h"

#ifndef TASKPROXIMITY_H_
#define TASKPROXIMITY_H_

class TaskProximity {
public:
	TaskProximity(SI1143*,Mutex*,Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>*);
	TaskProximity(SI1143*,Mutex*,Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskProximity();

	osStatus start(SI1143_MODE);
	osStatus stop();

	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	TASK_STATE state;

	SI1143* si1143;
	SI1143_MODE si1143Mode;

	static void callBack(void const *);
	void measureProximity();

	void setQueue(Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setSI1143Mode(SI1143_MODE);
	SI1143_MODE getSI1143Mode();

	void setState(TASK_STATE);
};

#endif /* TASKPROXIMITY_H_ */
