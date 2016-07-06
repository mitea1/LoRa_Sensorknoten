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
| Application_Mode|Task
Light  |Task
Temperature|Task
Pressure|Task
Humidity|Task
Acceleration|Task
Gyroscope|Task
Magnetometer|Task
Proximity|Task
GPS|
|---------|:---------:|:----------:|:---------:|:--------:|:--------:|:---------:|:--------:|:--------:|:--------:|
| Application_Mode_1 |X|X|X|X|X|X|X|X|X|X|
| Application_Mode_2 | |X|X|X| | | | | |X|
| Application_Mode_3 | |X|X|X| | | | | | |
| Application_Mode_4 | | | | |X|X|X| | |X|
| Application_Mode_5 | | | | |X|X|X| | | |
| Application_Mode_6 |X|X| | |X| | | | |X|
| Application_Mode_7 |X|X| | |X| | | | | |
| Application_Mode_8 |X| | | | | | | | |X|
| Application_Mode_9 |X| | | | | | | | | |
| Application_Mode_10| | | | | | | | |X|X|
| Application_Mode_11| | | | | | | | |X| |
