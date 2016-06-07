#include "SensorHandler.h"
#include "ApplicationConfig.h"

int main() {


	SensorHandler sensorHandler;
	sensorHandler.init(APPLICATION_MODE_TEST_MAX44009);
    while (true) {

    }

    return 0;
}
