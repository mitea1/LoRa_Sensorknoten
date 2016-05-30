/*
 * Task.h
 *
 *  Created on: May 26, 2016
 *      Author: Adrian
 */

#ifndef TASK_H_
#define TASK_H_

#include <Thread.h>
#include <Queue.h>
#include "MAX44009.h"

class Task: public rtos::Thread {
public:
	Task(rtos::Queue<MAX44009Message,1>*);
	virtual ~Task();
private:
	rtos::Queue<MAX44009Message,1>* queue;
	static void run(void const *);

};

#endif /* TASK_H_ */
