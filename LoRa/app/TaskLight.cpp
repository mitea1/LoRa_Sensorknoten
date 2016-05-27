/*
 * TaskLight.cpp
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#include "TaskLight.h"



TaskLight::TaskLight(MAX44009* max44009,Mutex* mutexI2C, Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue){
	this->max44009 = max44009;
	this->mutexI2C = mutexI2C;
	this->queue = queue;
}

TaskLight::TaskLight(MAX44009* max44009,rtos::Mutex* mutexI2C,
		rtos::Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stack_size, unsigned char *stack_pointer):TaskLight(max44009,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stack_size);
	setStackPointer(stack_pointer);
}

TaskLight::~TaskLight() {
	// TODO Auto-generated destructor stub
}

osStatus TaskLight::start(){
	this->thread = new rtos::Thread(callBack,this);
}

void TaskLight::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskLight* constInstance = static_cast<const TaskLight* >(data);
	TaskLight* instance = const_cast<TaskLight*>(constInstance);

	instance->measureLight();
}

void TaskLight::measureLight(){
	MAX44009Message max44009Message;

	while(true){
		mutexI2C->lock(osWaitForever);
		max44009Message.lux = max44009->getLux();
		mutexI2C->unlock();

		queue->put(&max44009Message,osWaitForever);
	}


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
