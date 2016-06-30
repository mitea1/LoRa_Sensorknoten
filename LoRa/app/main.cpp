#include "Application.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"

int main() {

	Application application;
	application.init(WEATHER_MEASUREMENT);

    while (true) {
    	sleep();
    }

    return 0;
}
