/*
 * TaskGyroscope.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskGyroscope.h"

TaskGyroscope::TaskGyroscope(MPU9250* mpu9250,Mutex* mutexI2C, Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queue){
	this->mpu9250 = mpu9250;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskGyroscope::TaskGyroscope(MPU9250* mpu9250,rtos::Mutex* mutexI2C,
	rtos::Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskGyroscope(mpu9250,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
}

TaskGyroscope::~TaskGyroscope() {
	// TODO Auto-generated destructor stub
}

osStatus TaskGyroscope::start(MPU9250_MODE desiredMPU9250Mode){
	setMPU9250Mode(desiredMPU9250Mode);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskGyroscope::stop(){
	delete this->thread;
}

void TaskGyroscope::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskGyroscope* constInstance = static_cast<const TaskGyroscope* >(data);
	TaskGyroscope* instance = const_cast<TaskGyroscope*>(constInstance);

	instance->measureGyroscope();
}

void TaskGyroscope::measureGyroscope(){
	MPU9250GyroscopeMessage mpu9250GyroscopeMessage;
	mutexI2C->lock(osWaitForever);
	mpu9250->init(getMPU9250Mode());
	mutexI2C->unlock();

	while(true){
		mutexI2C->lock(osWaitForever);
		mpu9250GyroscopeMessage.xGyro = mpu9250->getXAxisGyro();
		mpu9250GyroscopeMessage.yGyro = mpu9250->getYAxisGyro();
		mpu9250GyroscopeMessage.zGyro = mpu9250->getZAxisGyro();
		mutexI2C->unlock();

		queue->put(&mpu9250GyroscopeMessage,osWaitForever);
	}


}

void TaskGyroscope::setQueue(Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskGyroscope::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskGyroscope::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskGyroscope::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskGyroscope::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskGyroscope::setMPU9250Mode(MPU9250_MODE desiredMode){
	this->mpu9250Mode = desiredMode;
}

MPU9250_MODE TaskGyroscope::getMPU9250Mode(){
	return this->mpu9250Mode;
}

