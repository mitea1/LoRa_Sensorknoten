/*
 * TaskLight.cpp
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#include "TaskLight.h"



TaskLight::TaskLight(MAX44009* max44009,Mutex* mutexI2C, Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue){
	this->max44009 = max44009;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskLight::TaskLight(MAX44009* max44009,rtos::Mutex* mutexI2C,
		rtos::Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskLight(max44009,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
}

TaskLight::~TaskLight() {
	// TODO Auto-generated destructor stub
}

osStatus TaskLight::start(MAX44009_MODE desiredMAX44009Mode){
	setMAX44009Mode(desiredMAX44009Mode);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskLight::stop(){
	delete this->thread;
}

void TaskLight::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskLight* constInstance = static_cast<const TaskLight* >(data);
	TaskLight* instance = const_cast<TaskLight*>(constInstance);

	instance->measureLight();
}

void TaskLight::measureLight(){
	MAX44009Message* max44009Message = new MAX44009Message();
	mutexI2C->lock(osWaitForever);
	max44009->init(getMAX44009Mode());
	mutexI2C->unlock();

	while(true){
		mutexI2C->lock(osWaitForever);
		max44009Message->setLux(max44009->getLux());
		mutexI2C->unlock();

		queue->put(max44009Message,osWaitForever);
		osDelay(LIGHT_TASK_DELAY_MS);
	}


}

void TaskLight::setQueue(Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskLight::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskLight::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskLight::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskLight::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskLight::setMAX44009Mode(MAX44009_MODE desiredMode){
	this->max44009Mode = desiredMode;
}

MAX44009_MODE TaskLight::getMAX44009Mode(){
	return this->max44009Mode;
}
