#include "mbed.h"
#include "mDot.h"
#include "MTSLog.h"
#include "uBlox.h"
#include "I2C_RT.h"
#include "MAX44009.h"
#include "BME280.h"
#include "MPU9250.h"
#include "LoRa.h"
#include "TaskLight.h"
#include "TaskTemperature.h"
#include "TaskHumidity.h"
#include "TaskPressure.h"
#include "TaskAcceleration.h"
#include "TaskGyroscope.h"
#include "TaskGPS.h"
#include "TaskDatahandler.h"
#include "main.h"
#include <string>
#include <vector>
#include <algorithm>


// these options must match the settings on your Conduit
// uncomment the following lines and edit their values to match your configuration
static std::string config_network_name = "<lora network id>";
static std::string config_network_pass = "<lora network key>";
static uint8_t config_frequency_sub_band = 1;

#define GPS_MESSAGE_LENGTH  36
#define BAUD_UART   9600
#define BAUD_USB    9600

RawSerial uart(XBEE_DOUT,XBEE_DIN);
RawSerial usb(USBTX,USBRX);
I2C_RT i2c_rt;

uBlox gpsSensor(&uart);
MAX44009 max44009(&i2c_rt);
BME280	bme280(&i2c_rt);
MPU9250 mpu9250(&i2c_rt);

Queue<MAX44009Message,LIGHT_QUEUE_LENGHT> queueLight;
Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT> queueTemperature;
Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT> queuePressure;
Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT> queueHumidity;
Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT> queueAcceleration;
Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT> queueGyro;
Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT> queueTesla;
Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT> queueGps;

QueueBundle queueBundle = {&queueLight,&queueTemperature,&queuePressure,&queueHumidity,
							&queueAcceleration,&queueGyro,&queueTesla,&queueGps};

rtos::Mutex mutexI2C;
rtos::Mutex mutexUART1;
rtos::Mutex mutexBME280;
rtos::Mutex mutexMAX44009;
rtos::Mutex mutexMPU9250;
rtos::Mutex mutexSi4103;
rtos::Mutex mutexUBlox;

int main() {

	mDot* dot;
	dot = mDot::getInstance();

	LoRa lora(dot,&usb);

	TaskLight taskLight(&max44009,&mutexI2C,&queueLight,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	TaskTemperature taskTemperature(&bme280,&mutexI2C,&queueTemperature,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	TaskHumidity taskHumidity(&bme280,&mutexI2C,&queueHumidity,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	TaskPressure taskPressure(&bme280,&mutexI2C,&queuePressure,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	TaskAcceleration taskAcceleration(&mpu9250,&mutexI2C,&queueAcceleration,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	TaskGyroscope taskGyroscope(&mpu9250,&mutexI2C,&queueGyro,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	TaskGPS taskGps(&gpsSensor,&mutexUART1,&queueGps,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);
	TaskDatahandler taskDatahandler(&lora,queueBundle,osPriorityNormal,DEFAULT_STACK_SIZE,NULL);


    uart.baud(BAUD_UART);
	uart.format(8,SerialBase::None,1);
	usb.baud(BAUD_USB);
	usb.format(8,SerialBase::None,1);

	taskDatahandler.setDebugSerial(&usb);
	taskLight.start(MAX44009_MODE_1);
	taskTemperature.start(BME280_MODE_1);
	taskHumidity.start(BME280_MODE_1);
	taskPressure.start(BME280_MODE_1);
	taskAcceleration.start(MPU9250_MODE_1);
	taskGyroscope.start(MPU9250_MODE_1);
	taskGps.start(uBLOX_MODE_1);
	taskDatahandler.start();



    while (true) {
//    	osDelay(std::max((uint32_t)5000, (uint32_t)dot->getNextTxMs()));
    }

    return 0;
}
