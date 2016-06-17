#include "Application.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"

int main() {


	Application application;
	application.init(APPLICATION_MODE_LORA_MEASUREMENT);

    while (true) {

    }

    return 0;
}
