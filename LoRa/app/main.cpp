#include "mbed.h"
#include "mDot.h"
#include "MTSLog.h"
#include "uBlox.h"
#include "I2C_RT.h"
#include "MAX44009.h"
#include "BME280.h"
#include "MPU9250.h"
#include "SI1143.h"
#include "LoRa.h"
#include "TaskLight.h"
#include "TaskTemperature.h"
#include "TaskHumidity.h"
#include "TaskPressure.h"
#include "TaskAcceleration.h"
#include "TaskGyroscope.h"
#include "TaskTesla.h"
#include "TaskGPS.h"
#include "TaskDatahandler.h"
#include "main.h"
#include <string>
#include <vector>
#include <algorithm>
#include "SensorHandler.h"
#include "ApplicationConfig.h"

int main() {


	SensorHandler sensorHandler;
	sensorHandler.init(APPLICATION_MODE_1);

    while (true) {

    }

    return 0;
}
