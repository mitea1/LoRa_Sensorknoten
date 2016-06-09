/*
 * TaskGyroscope.h
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */
#include "MPU9250.h"
#include "MPU9250GyroscopeMessage.h"
#include "main.h"

#ifndef TASKGYROSCOPE_H_
#define TASKGYROSCOPE_H_

class TaskGyroscope {
public:
	TaskGyroscope(MPU9250*,Mutex*, Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>*);
	TaskGyroscope(MPU9250*,Mutex*,Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskGyroscope();

	osStatus start();
	osStatus stop();

	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	TASK_STATE state;

	MPU9250* mpu9250;

	static void callBack(void const *);
	void measureGyroscope();

	void setQueue(Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setState(TASK_STATE);

};

#endif /* TASKGYROSCOPE_H_ */
