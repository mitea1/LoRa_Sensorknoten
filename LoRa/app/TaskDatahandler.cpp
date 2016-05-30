/*
 * TaskDatahandler.cpp
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#include "TaskDatahandler.h"

TaskDatahandler::TaskDatahandler(QueueBundle queueBundle,
		osPriority priority,uint32_t stackSize, unsigned char* stackPointer){
	setQueueBundle(queueBundle);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
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
		getMessagesFromSensorQueues();
		forwardSensorMessages();
		osDelay(DATAHANLDER_TASK_DELAY_MS);
	}

}

void TaskDatahandler::getMessagesFromSensorQueues(){
	lightMeasureEvent = queueBundle.queueLight->get(0);
	temperatureMeasureEvent = queueBundle.queueTemperature->get(0);
	pressureMeasureEvent = queueBundle.queuePressure->get(0);
	humidityMeasureEvent = queueBundle.queueHumidity->get(0);
	accelerationMeasureEvent = queueBundle.queueAcceleration->get(0);
	gyroscopeMeasureEvent = queueBundle.queueGyro->get(0);
	teslaMeasureEvent = queueBundle.queueTesla->get(0);
}

void TaskDatahandler::forwardSensorMessages(){
	if (lightMeasureEvent.status == osEventMessage) {
		MAX44009Message* luxMessage = (MAX44009Message*)lightMeasureEvent.value.p;
		debugSerial->printf("Lux: %.2f\n",luxMessage->lux);
	}

	if (temperatureMeasureEvent.status == osEventMessage) {
		BME280TemperatureMessage* temperatureMessage = (BME280TemperatureMessage*)temperatureMeasureEvent.value.p;
		debugSerial->printf("Temperature: %.2f\n",temperatureMessage->temperature);
	}

	if (pressureMeasureEvent.status == osEventMessage) {
		BME280PresssureMessage* pressureMessage = (BME280PresssureMessage*)pressureMeasureEvent.value.p;
		debugSerial->printf("Pressure: %.2f\n",pressureMessage->pressure);
	}
	
	if (humidityMeasureEvent.status == osEventMessage) {
		BME280HumidityMessage* humidityMessage = (BME280HumidityMessage*)humidityMeasureEvent.value.p;
		debugSerial->printf("Humidity: %.2f\n",humidityMessage->humidity);
	}
	
	if (accelerationMeasureEvent.status == osEventMessage) {
		MPU9250AccelerationMessage* accelerationMessage = (MPU9250AccelerationMessage*)accelerationMeasureEvent.value.p;
		debugSerial->printf("Acceleration X: %.2f\n",accelerationMessage->xAcceleration);
		debugSerial->printf("Acceleration Y: %.2f\n",accelerationMessage->yAcceleration);
		debugSerial->printf("Acceleration Z: %.2f\n",accelerationMessage->zAcceleration);
	}
	
	if (gyroscopeMeasureEvent.status == osEventMessage) {
		MPU9250GyroscopeMessage* gyroscopeMessage = (MPU9250GyroscopeMessage*)gyroscopeMeasureEvent.value.p;
		debugSerial->printf("Gyroscope X: %.2f\n",gyroscopeMessage->xGyro);
		debugSerial->printf("Gyroscope Y: %.2f\n",gyroscopeMessage->yGyro);
		debugSerial->printf("Gyroscope Z: %.2f\n",gyroscopeMessage->zGyro);
	}
}

void TaskDatahandler::setQueueBundle(QueueBundle queueBundle){
	this->queueBundle = queueBundle;
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


