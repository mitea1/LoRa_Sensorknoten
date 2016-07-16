#include "Application.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"

int main() {

	Application application;
	application.init(ORIENTATATION_MEASUREMENT);

    while (true) {
    	sleep();
    }

    return 0;
}
