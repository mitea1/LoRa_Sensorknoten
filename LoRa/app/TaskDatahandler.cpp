/*
 * TaskDatahandler.cpp
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#include "TaskDatahandler.h"

TaskDatahandler::TaskDatahandler(Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queueLight,
		osPriority priority,uint32_t stackSize, unsigned char* stackPointer){
	this->queueLight = queueLight;

}

TaskDatahandler::~TaskDatahandler() {
	// TODO Auto-generated destructor stub
}

osStatus TaskDatahandler::start(){
	this->thread = new rtos::Thread(callBack,this);
}

void TaskDatahandler::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskDatahandler* constInstance = static_cast<const TaskDatahandler* >(data);
	TaskDatahandler* instance = const_cast<TaskDatahandler*>(constInstance);

	instance->handleData();
}

void TaskDatahandler::handleData(){

	while(true){
		osEvent event = queueLight->get(0);
		if (event.status == osEventMessage) {
			MAX44009Message *message = (MAX44009Message*)event.value.p;
			debugSerial->printf("Lux: %.2f\n",message->lux);
		}
		osDelay(DATAHANLDER_TASK_DELAY_MS);
	}

}

void TaskDatahandler::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskDatahandler::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskDatahandler::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskDatahandler::setDebugSerial(RawSerial* debugSerial){
	this->debugSerial = debugSerial;
}
