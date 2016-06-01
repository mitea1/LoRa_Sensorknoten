/*
 * SensorMessage.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#ifndef SENSORMESSAGE_H_
#define SENSORMESSAGE_H_

class SensorMessage {
public:
	SensorMessage();
	virtual ~SensorMessage();

	virtual char* getLoRaMessageString();

private:
	virtual char* getLoRaMessageId();

};

#endif /* SENSORMESSAGE_H_ */
