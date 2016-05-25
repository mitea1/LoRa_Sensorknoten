/*
 * MAX44009Config.h
 *
 *  Created on: 25.05.2016
 *      Author: Adrian
 */
#include <stdint-gcc.h>
#ifndef APP_MAX44009CONFIG_H_
#define APP_MAX44009CONFIG_H_

#define MAX_44009_CONTINOUS_MODE_ON			0b1
#define MAX_44009_CONTINOUS_MODE_OFF		0b0
//Integration Times
#define MAX_44009_INTEGRATION_TIME_800_MS	0b000
#define MAX_44009_INTEGRATION_TIME_400_MS	0b001
#define MAX_44009_INTEGRATION_TIME_200_MS	0b010
#define MAX_44009_INTEGRATION_TIME_100_MS	0b011
#define MAX_44009_INTEGRATION_TIME_50_MS	0b100
#define MAX_44009_INTEGRATION_TIME_25_MS	0b101
#define MAX_44009_INTEGRATION_TIME_12_5_MS	0b110
#define MAX_44009_INTEGRATION_TIME_6_25_MS	0b111

enum MAX44009_MODE{
	MAX44009_MODE_1,
	MAX44009_MODE_2,
	MAX44009_MODE_3,
	MAX44009_MODE_4,
	MAX44009_MODE_5
};

class MAX44009Config {
public:
	MAX44009Config();
	virtual ~MAX44009Config();
	void build(MAX44009_MODE);

	uint8_t getIntegrationTime();
	uint8_t getContinousMode();

private:
	uint8_t integrationTime;
	uint8_t continousMode;

	void setIntegrationTime(uint8_t);
	void setContinousMode(uint8_t);
};

#endif /* APP_MAX44009CONFIG_H_ */
