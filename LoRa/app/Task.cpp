/*
 * Task.cpp
 *
 *  Created on: May 26, 2016
 *      Author: Adrian
 */

#include "Task.h"

Task::Task(rtos::Queue<MAX44009Message,1>* queue):rtos::Thread(run) {
	// TODO Auto-generated constructor stub
	this->queue = queue;

}

Task::~Task() {
	// TODO Auto-generated destructor stub

}

void Task::run(void const *args){
	//do something

}

