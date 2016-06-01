/*
 * TaskGPS.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskGPS.h"

TaskGPS::TaskGPS(uBlox* uBlox,Mutex* mutexUART, Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue){
	this->mUBlox = uBlox;
	setMutex(mutexUART);
	setQueue(queue);
}

TaskGPS::TaskGPS(uBlox* uBlox,rtos::Mutex* mutexUART,
		rtos::Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskGPS(uBlox,mutexUART,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
}

TaskGPS::~TaskGPS() {
	// TODO Auto-generated destructor stub
}

osStatus TaskGPS::start(uBLOX_MODE desiredMode){
	setUBLOXMode(desiredMode);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskGPS::stop(){
	delete this->thread;
}

void TaskGPS::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskGPS* constInstance = static_cast<const TaskGPS* >(data);
	TaskGPS* instance = const_cast<TaskGPS*>(constInstance);

	instance->measureGps();
}

void TaskGPS::measureGps(){
	UBloxGPSMessage uBloxGPSMessage;
	mutexUART->lock(osWaitForever);
	mUBlox->init(getUBLOXMode());
	mutexUART->unlock();

	while(true){
		mutexUART->lock(osWaitForever);
		uBloxGPSMessage.setLongitude(mUBlox->getLongitude());
		uBloxGPSMessage.setLatitude(mUBlox->getLatitude());
		mutexUART->unlock();

		queue->put(&uBloxGPSMessage,osWaitForever);
		osDelay(GPS_TASK_DELAY_MS);
	}


}

void TaskGPS::setQueue(Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskGPS::setMutex(Mutex* mutex){
	this->mutexUART = mutex;
}

void TaskGPS::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskGPS::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskGPS::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskGPS::setUBLOXMode(uBLOX_MODE desiredMode){
	this->uBloxMode = desiredMode;
}

uBLOX_MODE TaskGPS::getUBLOXMode(){
	return this->uBloxMode;
}

