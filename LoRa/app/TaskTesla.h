/*
 * TaskTesla.h
 *
 *  Created on: 01.06.2016
 *      Author: Adrian
 */
#include "MPU9250.h"
#include "MPU9250TeslaMessage.h"
#include "main.h"

#ifndef APP_TASKTESLA_H_
#define APP_TASKTESLA_H_

class TaskTesla {
public:
	TaskTesla(MPU9250*,Mutex*, Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*);
	TaskTesla(MPU9250*,Mutex*,Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskTesla();

	osStatus start(MPU9250_MODE);
	osStatus stop();

	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority = osPriorityNormal;
	uint32_t stack_size = DEFAULT_STACK_SIZE;
	unsigned char *stack_pointer = NULL;

	TASK_STATE state;

	MPU9250* mpu9250;
	MPU9250_MODE mpu9250Mode;

	static void callBack(void const *);
	void measureTesla();

	void setQueue(Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setMPU9250Mode(MPU9250_MODE);
	MPU9250_MODE getMPU9250Mode();

	void setState(TASK_STATE);
};

#endif /* APP_TASKTESLA_H_ */
