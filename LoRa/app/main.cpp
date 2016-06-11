#include "SensorHandler.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"

int main() {


//	SensorHandler sensorHandler;
//	sensorHandler.init(APPLICATION_MODE_TEST_uBlox);
	RawSerial* uart = new RawSerial(XBEE_DOUT,XBEE_DIN);
	RawSerial* usb = new RawSerial(USBTX,USBRX);
	uart->baud(9600);
	usb->baud(9600);
	UART_Tunnel uartTunnel(uart,usb);

    while (true) {

    }

    return 0;
}
