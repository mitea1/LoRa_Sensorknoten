#include "SensorHandler.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"

int main() {



	SensorHandler sensorHandler;
	sensorHandler.init(APPLICATION_MODE_TEST);
//	mbed::RawSerial* uartSerial = new mbed::RawSerial(XBEE_DOUT,XBEE_DIN);
//	mbed::RawSerial* usbSerial = new mbed::RawSerial(USBTX,USBRX);
//
//	uartSerial->baud(9600);
//	usbSerial->baud(9600);
//
//	UART_Tunnel uartTunnel(uartSerial,usbSerial);
    while (true) {

    }

    return 0;
}
