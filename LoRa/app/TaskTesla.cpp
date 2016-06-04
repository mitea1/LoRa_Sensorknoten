/*
 * TaskTesla.cpp
 *
 *  Created on: 01.06.2016
 *      Author: Adrian
 */

#include "TaskTesla.h"

TaskTesla::TaskTesla(MPU9250* mpu9250,Mutex* mutexI2C, Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue){
	this->mpu9250 = mpu9250;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskTesla::TaskTesla(MPU9250* mpu9250,rtos::Mutex* mutexI2C,
	rtos::Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskTesla(mpu9250,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(ApplicationConfig::SLEEPING_STATE);
}

TaskTesla::~TaskTesla() {
	// TODO Auto-generated destructor stub
}

osStatus TaskTesla::start(MPU9250_MODE desiredMPU9250Mode){
	setMPU9250Mode(desiredMPU9250Mode);
	setState(ApplicationConfig::RUNNING_STATE);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskTesla::stop(){
	setState(ApplicationConfig::SLEEPING_STATE);
	delete this->thread;
}

void TaskTesla::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskTesla* constInstance = static_cast<const TaskTesla* >(data);
	TaskTesla* instance = const_cast<TaskTesla*>(constInstance);

	instance->measureTesla();
}

void TaskTesla::measureTesla(){
	MPU9250TeslaMessage mpu9250TeslaMessage;
	mutexI2C->lock(osWaitForever);
	mpu9250->init(getMPU9250Mode());
	mutexI2C->unlock();

	while(true){
		mutexI2C->lock(osWaitForever);
		mpu9250TeslaMessage.setXTesla(mpu9250->getXAxisTesla());
		mpu9250TeslaMessage.setYTesla(mpu9250->getYAxisTesla());
		mpu9250TeslaMessage.setZTesla(mpu9250->getZAxisTesla());
		mutexI2C->unlock();

		queue->put(&mpu9250TeslaMessage,osWaitForever);
		osDelay(TESLA_TASK_DELAY_MS);
	}
}

void TaskTesla::setQueue(Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskTesla::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskTesla::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskTesla::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskTesla::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskTesla::setMPU9250Mode(MPU9250_MODE desiredMode){
	this->mpu9250Mode = desiredMode;
}

MPU9250_MODE TaskTesla::getMPU9250Mode(){
	return this->mpu9250Mode;
}

void TaskTesla::setState(ApplicationConfig::TASK_STATE state){
	this->state = state;
}

ApplicationConfig::TASK_STATE TaskTesla::getState(){
	return state;
}
