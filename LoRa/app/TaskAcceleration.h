/*
 * TaskAcceleration.h
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */
#include "MPU9250.h"
#include "main.h"

#ifndef TASKACCELERATION_H_
#define TASKACCELERATION_H_

class TaskAcceleration {
public:
	TaskAcceleration(MPU9250*,Mutex*, Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>*);
	TaskAcceleration(MPU9250*,Mutex*,Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskAcceleration();

	osStatus start(MPU9250_MODE);
	osStatus stop();

private:
	rtos::Thread* thread;
	rtos::Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;


	MPU9250* mpu9250;
	MPU9250_MODE mpu9250Mode;

	static void callBack(void const *);
	void measureAcceleration();

	void setQueue(Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setMPU9250Mode(MPU9250_MODE);
	MPU9250_MODE getMPU9250Mode();

};

#endif /* TASKACCELERATION_H_ */
