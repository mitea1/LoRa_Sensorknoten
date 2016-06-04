/*
 * TaskPressure.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskPressure.h"

TaskPressure::TaskPressure(BME280* bme280,Mutex* mutexI2C, Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue){
	this->bme280 = bme280;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskPressure::TaskPressure(BME280* bme280,rtos::Mutex* mutexI2C,
	rtos::Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskPressure(bme280,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(ApplicationConfig::SLEEPING_STATE);
}

TaskPressure::~TaskPressure() {
	// TODO Auto-generated destructor stub
}

osStatus TaskPressure::start(BME280_MODE desiredBME280Mode){
	setBME280Mode(desiredBME280Mode);
	setState(ApplicationConfig::RUNNING_STATE);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskPressure::stop(){
	setState(ApplicationConfig::SLEEPING_STATE);
	delete this->thread;
}

void TaskPressure::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskPressure* constInstance = static_cast<const TaskPressure* >(data);
	TaskPressure* instance = const_cast<TaskPressure*>(constInstance);

	instance->measurePressure();
}

void TaskPressure::measurePressure(){
	BME280PressureMessage bme280PressureMessage;
	mutexI2C->lock(osWaitForever);
	bme280->init(getBME280Mode());
	mutexI2C->unlock();

	while(true){
		mutexI2C->lock(osWaitForever);
		bme280PressureMessage.setPressure(bme280->getPressureFloat());
		mutexI2C->unlock();

		queue->put(&bme280PressureMessage,osWaitForever);
		osDelay(PRESSURE_TASK_DELAY_MS);
	}


}

void TaskPressure::setQueue(Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskPressure::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskPressure::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskPressure::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskPressure::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskPressure::setBME280Mode(BME280_MODE desiredMode){
	this->bme280Mode = desiredMode;
}

BME280_MODE TaskPressure::getBME280Mode(){
	return this->bme280Mode;
}

void TaskPressure::setState(ApplicationConfig::TASK_STATE state){
	this->state = state;
}

ApplicationConfig::TASK_STATE TaskPressure::getState(){
	return state;
}

