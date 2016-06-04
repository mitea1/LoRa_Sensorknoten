/*
 * TaskDatahandler.cpp
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#include "TaskDatahandler.h"

TaskDatahandler::TaskDatahandler(LoRa* lora,QueueBundle queueBundle,
		osPriority priority,uint32_t stackSize, unsigned char* stackPointer){
	setLoRa(lora);
	setQueueBundle(queueBundle);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(ApplicationConfig::SLEEPING_STATE);
}

TaskDatahandler::~TaskDatahandler() {
	// TODO Auto-generated destructor stub
}

osStatus TaskDatahandler::start(){
	setState(ApplicationConfig::RUNNING_STATE);
	this->thread = new rtos::Thread(callBack,this);
}

void TaskDatahandler::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskDatahandler* constInstance = static_cast<const TaskDatahandler* >(data);
	TaskDatahandler* instance = const_cast<TaskDatahandler*>(constInstance);

	instance->handleData();
}

void TaskDatahandler::handleData(){
	//lora->init();

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
	gpsMeasureEvent = queueBundle.queueGps->get(0);
}

void TaskDatahandler::forwardSensorMessages(){
	std::string loraMessage;
	std::vector<uint8_t> data;

	int32_t ret;

	debugSerial->printf("\n");
	if (lightMeasureEvent.status == osEventMessage) {
		MAX44009Message* luxMessage = (MAX44009Message*)lightMeasureEvent.value.p;
		debugSerial->printf("%s\n",luxMessage->getLoRaMessageString());
		loraMessage.append(luxMessage->getLoRaMessageString());
	}

	if (temperatureMeasureEvent.status == osEventMessage) {
		BME280TemperatureMessage* temperatureMessage = (BME280TemperatureMessage*)temperatureMeasureEvent.value.p;
		debugSerial->printf("%s\n",temperatureMessage->getLoRaMessageString());
		loraMessage.append(temperatureMessage->getLoRaMessageString());
	}

	if (pressureMeasureEvent.status == osEventMessage) {
		BME280PressureMessage* pressureMessage = (BME280PressureMessage*)pressureMeasureEvent.value.p;
		debugSerial->printf("%s\n",pressureMessage->getLoRaMessageString());
		loraMessage.append(pressureMessage->getLoRaMessageString());
	}
	
	if (humidityMeasureEvent.status == osEventMessage) {
		BME280HumidityMessage* humidityMessage = (BME280HumidityMessage*)humidityMeasureEvent.value.p;
		debugSerial->printf("%s\n",humidityMessage->getLoRaMessageString());
		loraMessage.append(humidityMessage->getLoRaMessageString());
	}
	
	if (accelerationMeasureEvent.status == osEventMessage) {
		MPU9250AccelerationMessage* accelerationMessage = (MPU9250AccelerationMessage*)accelerationMeasureEvent.value.p;
		debugSerial->printf("%s\n",accelerationMessage->getLoRaMessageString());
		loraMessage.append(accelerationMessage->getLoRaMessageString());
	}
	
	if (gyroscopeMeasureEvent.status == osEventMessage) {
		MPU9250GyroscopeMessage* gyroscopeMessage = (MPU9250GyroscopeMessage*)gyroscopeMeasureEvent.value.p;
		debugSerial->printf("%s\n",gyroscopeMessage->getLoRaMessageString());
		loraMessage.append(gyroscopeMessage->getLoRaMessageString());
	}

	if (teslaMeasureEvent.status == osEventMessage) {
		MPU9250TeslaMessage* teslaMessage = (MPU9250TeslaMessage*)teslaMeasureEvent.value.p;
		debugSerial->printf("%s\n",teslaMessage->getLoRaMessageString());
		loraMessage.append(teslaMessage->getLoRaMessageString());
	}

	if(gpsMeasureEvent.status == osEventMessage){
		UBloxGPSMessage* uBloxGpsMessage = (UBloxGPSMessage*)gpsMeasureEvent.value.p;
		debugSerial->printf("%s\n",uBloxGpsMessage->getLoRaMessageString());
		loraMessage.append(uBloxGpsMessage->getLoRaMessageString());
	}
	debugSerial->printf("\n");
	// format data for sending to the gateway
	for (std::string::iterator it = loraMessage.begin(); it != loraMessage.end(); it++){
		data.push_back((uint8_t) *it);
	}
	//lora->send(data);

	loraMessage.clear();

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

void TaskDatahandler::setLoRa(LoRa* lora){
	this->lora = lora;
}

void TaskDatahandler::setState(ApplicationConfig::TASK_STATE state){
	this->state = state;
}

ApplicationConfig::TASK_STATE TaskDatahandler::getState(){
	return state;
}




