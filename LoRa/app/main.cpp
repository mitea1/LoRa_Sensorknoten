#include "mbed.h"
#include "mDot.h"
#include "MTSLog.h"
#include "uBlox.h"
#include "I2C_RT.h"
#include "MAX44009.h"
#include "BME280.h"
#include "MPU9250.h"
#include "SI1143.h"
#include <string>
#include <vector>
#include <algorithm>

//Testbranch add

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
SI1143 si1143(&i2c_rt);
//mbed::I2C i2c(I2C_SDA,I2C_SCL);
//SI1143 si1143(&i2c);
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
//	lightSensor.init(MAX44009_MODE_1);
//	mpu9250.init(MPU9250_MODE_3);
//	bme280.init(BME280_MODE_1);

	si1143.init();
//	si1143.restart(0);


//	double lux;
//	float humidity;
//	float pressure;
//	float temperature;
//	float xAxisAcceleration;
//	float yAxisAcceleration;
//	float zAxisAcceleration;
//	float xGyro;
//	float yGyro;
//	float zGyro;
	uint32_t proximity;
	uint32_t siLight,siValue;
	while(true){
//		lux = lightSensor.getLux();
//		humidity = bme280.getHumidityFloat();
//		pressure = bme280.getPressureFloat();
//		temperature = bme280.getTemperatureFloat();
//		xAxisAcceleration = mpu9250.getXAxisAcceleration();
//		yAxisAcceleration = mpu9250.getYAxisAcceleration();
//		zAxisAcceleration = mpu9250.getZAxisAcceleration();
//		xGyro = mpu9250.getXAxisGyro();
//		yGyro = mpu9250.getYAxisGyro();
//		zGyro = mpu9250.getZAxisGyro();
		proximity = si1143.getProximity();
		siLight = si1143.getLight();
		siValue = si1143.getValue();
//		proximity = si1143.get_ps1(4);

//		usb.printf("Lux: %.2f \n",lux);
//		usb.printf("Humidity: %.2f \n",humidity);
//		usb.printf("Pressure: %.2f \n",pressure);
//		usb.printf("Temperature: %.2f \n",temperature);
//		usb.printf("X Accel: %.2f G \n",xAxisAcceleration);
//		usb.printf("Y Accel: %.2f G \n",yAxisAcceleration);
//		usb.printf("Z Accel: %.2f G \n",zAxisAcceleration);
//		usb.printf("X Angle: %.2f deg/s \n",xGyro);
//		usb.printf("Y Angle: %.2f deg/s \n",yGyro);
//		usb.printf("Z Angle: %.2f deg/s \n",zGyro);
		usb.printf("Proximity: %d \n\n",proximity);
		usb.printf("Light: %d \n\n",siLight);
		usb.printf("Light: %d \n\n",siValue);
    	osDelay(50);
    }

    //Leave this while here otherwhise some linker problem occurs
    while (true) {
        osDelay(std::max((uint32_t)5000, (uint32_t)dot->getNextTxMs()));
    }

    return 0;
}
