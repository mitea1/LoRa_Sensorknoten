#include "mbed.h"
#include "mDot.h"
#include "MTSLog.h"
#include "uBlox.h"
#include "I2C_RT.h"
#include "MAX44009.h"
#include "BME280.h"
#include "MPU9250.h"
#include <string>
#include <vector>
#include <algorithm>

// these options must match the settings on your Conduit
// uncomment the following lines and edit their values to match your configuration
static std::string config_network_name = "<lora network id>";
static std::string config_network_pass = "<lora network key>";
//static uint8_t config_frequency_sub_band = 1;

#define GPS_MESSAGE_LENGTH  36
#define BAUD_UART   9600
#define BAUD_USB    9600

RawSerial uart(XBEE_DOUT,XBEE_DIN);
RawSerial usb(USBTX,USBRX);
uBlox gpsSensor(&uart);
I2C_RT i2c_rt;
MAX44009 lightSensor(&i2c_rt);
BME280	bme280(&i2c_rt);
MPU9250 mpu9250(&i2c_rt);

int main() {

    mDot* dot;
    //std::vector<uint8_t> data;
    std::string data_str = "hello!";

    // get a mDot handle
    dot = mDot::getInstance();

    uart.baud(BAUD_UART);
	uart.format(8,SerialBase::None,1);
	usb.baud(BAUD_USB);
	usb.format(8,SerialBase::None,1);


	//TODO check mpu init. scale is wrong
	mpu9250.init(MODE_3);
	bme280.init();

	double lux;
	float humidity;
	float pressure;
	float temperature;
	float xAxisAcceleration;
	float yAxisAcceleration;
	float zAxisAcceleration;
	float xGyro;
	float yGyro;
	float zGyro;
	while(true){
		lux = lightSensor.getLux();
		humidity = bme280.getHumidityFloat();
		pressure = bme280.getPressureFloat();
		temperature = bme280.getTemperatureFloat();
		xAxisAcceleration = mpu9250.getXAxisAcceleration();
		yAxisAcceleration = mpu9250.getYAxisAcceleration();
		zAxisAcceleration = mpu9250.getZAxisAcceleration();
		xGyro = mpu9250.getXAxisGyro();
		yGyro = mpu9250.getYAxisGyro();
		zGyro = mpu9250.getZAxisGyro();
		usb.printf("Lux: %.2f \n",lux);
		usb.printf("Humidity: %.2f \n",humidity);
		usb.printf("Pressure: %.2f \n",pressure);
		usb.printf("Temperature: %.2f \n",temperature);
		usb.printf("X Accel: %.2f G \n",xAxisAcceleration);
		usb.printf("Y Accel: %.2f G \n",yAxisAcceleration);
		usb.printf("Z Accel: %.2f G \n",zAxisAcceleration);
		usb.printf("X Angle: %.2f deg/s \n",xGyro);
		usb.printf("Y Angle: %.2f deg/s \n",yGyro);
		usb.printf("Z Angle: %.2f deg/s \n\n",zGyro);
    	osDelay(500);
    }

    //Leave this while here otherwhise some linker problem occurs
    while (true) {
        osDelay(std::max((uint32_t)5000, (uint32_t)dot->getNextTxMs()));
    }

    return 0;
}
