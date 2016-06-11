/*
 * UARTTunnel.h
 *
 *  Created on: 10.06.2016
 *      Author: Adrian
 */
#include "RawSerial.h"

#ifndef APP_UARTTUNNEL_H_
#define APP_UARTTUNNEL_H_

class UART_Tunnel {
public:
	UART_Tunnel();
	UART_Tunnel(mbed::RawSerial*,mbed::RawSerial*);
	virtual ~UART_Tunnel();

private:
	mbed::RawSerial* uartSerial;
	mbed::RawSerial* usbSerial;

	void onUartRx();
	void onUsbRx();
};

#endif /* APP_UARTTUNNEL_H_ */
