/*
 * TaskHumidity.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskHumidity.h"

TaskHumidity::TaskHumidity(BME280* bme280,Mutex* mutexI2C, Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue){
	this->bme280 = bme280;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskHumidity::TaskHumidity(BME280* bme280,rtos::Mutex* mutexI2C,
		rtos::Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskHumidity(bme280,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
}

TaskHumidity::~TaskHumidity() {
	// TODO Auto-generated destructor stub
}

osStatus TaskHumidity::start(BME280_MODE desiredBME280Mode){
	setBME280Mode(desiredBME280Mode);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskHumidity::stop(){
	delete this->thread;
}

void TaskHumidity::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskHumidity* constInstance = static_cast<const TaskHumidity* >(data);
	TaskHumidity* instance = const_cast<TaskHumidity*>(constInstance);

	instance->measureHumidity();
}

void TaskHumidity::measureHumidity(){
	BME280HumidityMessage bme280HumidityMessage;
	mutexI2C->lock(osWaitForever);
	bme280->init(getBME280Mode());
	mutexI2C->unlock();

	while(true){
		mutexI2C->lock(osWaitForever);
		bme280HumidityMessage.humidity = bme280->getHumidityFloat();
		mutexI2C->unlock();

		queue->put(&bme280HumidityMessage,osWaitForever);
		osDelay(HUMIDITY_TASK_DELAY_MS);
	}


}

void TaskHumidity::setQueue(Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskHumidity::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskHumidity::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskHumidity::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskHumidity::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskHumidity::setBME280Mode(BME280_MODE desiredMode){
	this->bme280Mode = desiredMode;
}

BME280_MODE TaskHumidity::getBME280Mode(){
	return this->bme280Mode;
}

