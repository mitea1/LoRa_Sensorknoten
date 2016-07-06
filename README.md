#LoRa-Sensornode Firmware for Multitech mDot
A multifunctional modular Library based on ARM mBed provides a widerange of functionality for several Sensors. 
It allows you to quickly build a Sensornode that measures specific data with its sensors and sends it via LoRaWAN.

##Supported Sensors
+ MAX44009 (Lux Measurment)
+ BME280 (Temperature, Pressure and Humdity Measurment)
+ MPU9250 (Acceleration, Gyroscope and Magnetometer)
+ Si1143 (Proximity up to 50cm)
+ uBlox M8Q (GPS Position)

##Idea
The Firmware has some predefined Application Modes running different Tasks(Measurements). Each mode can be used in a different Scenario.
And you can build your own modes for your own Scenario in which you want to use the Sensornode.

###Application Modes
| Application_Mode|TaskLight  |TaskTemperature|TaskPressure|TaskHumidity|TaskAcceleration|TaskGyroscope|TaskMagnetometer|TaskProximity|TaskGPS|
|---------|:---------:|:----------:|:---------:|:--------:|:--------:|:---------:|:--------:|:--------:|:--------:|
| Application_Mode_1|X|X|X|X|X|X|X|X|X|X|
