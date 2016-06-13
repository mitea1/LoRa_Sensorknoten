/*
 * ApplicationConfig.h
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */
#include "BME280Config.h"
#include "MPU9250Config.h"
#include "uBloxConfig.h"
#include "MAX44009Config.h"
#include "SI1143Config.h"
#include "LoRaConfig.h"
#include "main.h"
#ifndef APPLICATIONCONFIG_H_
#define APPLICATIONCONFIG_H_

enum APPLICATION_MODE {
	APPLICATION_MODE_1,
	APPLICATION_MODE_2,
	APPLICATION_MODE_3,
	APPLICATION_MODE_4,
	APPLICATION_MODE_5,
	APPLICATION_MODE_6,
	APPLICATION_MODE_7,
	APPLICATION_MODE_8,
	APPLICATION_MODE_9,
	APPLICATION_MODE_10,
	APPLICATION_MODE_11,
	APPLICATION_MODE_99,
	APPLICATION_MODE_TEST,
	APPLICATION_MODE_TEST_MAX44009,
	APPLICATION_MODE_TEST_BME280,
	APPLICATION_MODE_TEST_MPU9250,
	APPLICATION_MODE_TEST_SI1143,
	APPLICATION_MODE_TEST_uBlox
};


class ApplicationConfig {
public:
	ApplicationConfig();
	virtual ~ApplicationConfig();

	void build(APPLICATION_MODE);

	MAX44009_MODE getMAX44009_MODE();
	BME280_MODE getBME280_MODE();
	MPU9250_MODE getMPU9250_MODE();
	SI1143_MODE getSI1143_MODE();
	uBLOX_MODE getuBlox_MODE();
	LORA_MODE getLORA_MODE();

	TASK_STATE getStateTaskLight();
	TASK_STATE getStateTaskTemperature();
	TASK_STATE getStateTaskPressure();
	TASK_STATE getStateTaskHumidity();
	TASK_STATE getStateTaskAcceleration();
	TASK_STATE getStateTaskGyroscope();
	TASK_STATE getStateTaskTesla();
	TASK_STATE getStateTaskProximity();
	TASK_STATE getStateTaskGPS();

	LORA_STATE getStateLoRa();

private:
	MAX44009_MODE max44009Mode;
	BME280_MODE bme280Mode;
	MPU9250_MODE mpu9250Mode;
	SI1143_MODE si1143Mode;
	uBLOX_MODE ubloxMode;
	LORA_MODE loraMode;

	TASK_STATE stateTaskLight;
	TASK_STATE stateTaskTemperature;
	TASK_STATE stateTaskPressure;
	TASK_STATE stateTaskHumidity;
	TASK_STATE stateTaskAcceleration;
	TASK_STATE stateTaskGyroscope;
	TASK_STATE stateTaskTesla;
	TASK_STATE stateTaskProximity;
	TASK_STATE stateTaskGPS;

	LORA_STATE stateLoRa;

	void setMAX44009_MODE(MAX44009_MODE);
	void setBME280_MODE(BME280_MODE);
	void setMPU9250_MODE(MPU9250_MODE);
	void setSI1143_MODE(SI1143_MODE);
	void setuBlox_MODE(uBLOX_MODE);
	void setLORA_MODE(LORA_MODE);

	void setStateTaskLight(TASK_STATE);
	void setStateTaskTemperature(TASK_STATE);
	void setStateTaskPressure(TASK_STATE);
	void setStateTaskHumidity(TASK_STATE);
	void setStateTaskAcceleration(TASK_STATE);
	void setStateTaskGyroscope(TASK_STATE);
	void setStateTaskTesla(TASK_STATE);
	void setStateTaskProximity(TASK_STATE);
	void setStateTaskGPS(TASK_STATE);

	void setStateLoRa(LORA_STATE);

};

#endif /* APPLICATIONCONFIG_H_ */
