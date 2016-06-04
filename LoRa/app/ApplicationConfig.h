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
#include "main.h"
#ifndef APPLICATIONCONFIG_H_
#define APPLICATIONCONFIG_H_

enum APPLICATION_MODE {
	APPLICATION_MODE_1,
	APPLICATION_MODE_2,
	APPLICATION_MODE_3
};

class ApplicationConfig {
public:
	ApplicationConfig();
	virtual ~ApplicationConfig();

	void build(APPLICATION_MODE);

	enum TASK_STATE {
		RUNNING_STATE = 1,
		SLEEPING_STATE = 0
	};

	MAX44009_MODE getMAX44009_MODE();
	BME280_MODE getBME280_MODE();
	MPU9250_MODE getMPU9250_MODE();
	SI1143_MODE getSI1143_MODE();
	uBLOX_MODE getuBlox_MODE();

	ApplicationConfig::TASK_STATE getStateTaskLight();
	ApplicationConfig::TASK_STATE getStateTaskTemperature();
	ApplicationConfig::TASK_STATE getStateTaskPressure();
	ApplicationConfig::TASK_STATE getStateTaskHumidity();
	ApplicationConfig::TASK_STATE getStateTaskAcceleration();
	ApplicationConfig::TASK_STATE getStateTaskGyroscope();
	ApplicationConfig::TASK_STATE getStateTaskTesla();
	ApplicationConfig::TASK_STATE getStateTaskProximity();
	ApplicationConfig::TASK_STATE getStateTaskGPS();

private:
	MAX44009_MODE max44009Mode;
	BME280_MODE bme280Mode;
	MPU9250_MODE mpu9250Mode;
	SI1143_MODE si1143Mode;
	uBLOX_MODE ubloxMode;

	ApplicationConfig::TASK_STATE stateTaskLight;
	ApplicationConfig::TASK_STATE stateTaskTemperature;
	ApplicationConfig::TASK_STATE stateTaskPressure;
	ApplicationConfig::TASK_STATE stateTaskHumidity;
	ApplicationConfig::TASK_STATE stateTaskAcceleration;
	ApplicationConfig::TASK_STATE stateTaskGyroscope;
	ApplicationConfig::TASK_STATE stateTaskTesla;
	ApplicationConfig::TASK_STATE stateTaskProximity;
	ApplicationConfig::TASK_STATE stateTaskGPS;

	void setMAX44009_MODE(MAX44009_MODE);
	void setBME280_MODE(BME280_MODE);
	void setMPU9250_MODE(MPU9250_MODE);
	void setSI1143_MODE(SI1143_MODE);
	void setuBlox_MODE(uBLOX_MODE);

	void setStateTaskLight(ApplicationConfig::TASK_STATE);
	void setStateTaskTemperature(ApplicationConfig::TASK_STATE);
	void setStateTaskPressure(ApplicationConfig::TASK_STATE);
	void setStateTaskHumidity(ApplicationConfig::TASK_STATE);
	void setStateTaskAcceleration(ApplicationConfig::TASK_STATE);
	void setStateTaskGyroscope(ApplicationConfig::TASK_STATE);
	void setStateTaskTesla(ApplicationConfig::TASK_STATE);
	void setStateTaskProximity(ApplicationConfig::TASK_STATE);
	void setStateTaskGPS(ApplicationConfig::TASK_STATE);

};

#endif /* APPLICATIONCONFIG_H_ */
