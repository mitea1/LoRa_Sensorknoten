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
| Application_Mode|TaskLight|TaskTemperature|TaskPressure|TaskHumidity|TaskAcceleration|TaskGyroscope|TaskMagnetometer|TaskProximity|TaskGPS|
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

<p>Einfache Tabelle mit Überschrift</p>
<table>
  <tr>
    <th>Vorname</th>
    <th>Nachname</th>
  </tr>
  <tr>
    <td>Max</td>
    <td>Mustermann</td>
  </tr>
  <tr>
    <td>Maxine</td>
    <td>Mustermann</td>
  </tr>
</table>

<p>Tabelle mit thead, tfoot, and tbody</p>
<table>
  <thead>
    <tr>
      <th>Header content 1</th>
      <th>Header content 2</th>
    </tr>
  </thead>
  <tfoot>
    <tr>
      <td>Footer content 1</td>
      <td>Footer content 2</td>
    </tr>
  </tfoot>
  <tbody>
    <tr>
      <td>Body content 1</td>
      <td>Body content 2</td>
    </tr>
  </tbody>
</table>

<p>Tabelle mit colgroup</p>
<table>
  <colgroup span="4" class="columns"></colgroup>
  <tr>
    <th>Länder</th>
    <th>Hauptstädte</th>
    <th>Bevölkerung</th>
    <th>Sprache</th>
  </tr>
  <tr>
    <td>USA</td>
    <td>Washington D.C.</td>
    <td>309 Millionen</td>
    <td>Englisch</td>
  </tr>
  <tr>
    <td>Schweden</td>
    <td>Stockholm</td>
    <td>9 Millionen</td>
    <td>Schwedisch</td>
  </tr>
</table>

<p>Tabelle mit colgroup und col</p>
<table>
  <colgroup>
    <col class="column1">
    <col class="columns2plus3" span="2">
  </colgroup>
  <tr>
    <th>Limone</th>
    <th>Zitrone</th>
    <th>Orange</th>
  </tr>
  <tr>
    <td>Grün</td>
    <td>Gelb</td>
    <td>Orange</td>
  </tr>
</table>

<p>Einfache Tabelle mit Beschreibung</p>
<table>
  <caption>Unglaublich tolle Beschreibung</caption>
  <tr>
    <td>Unglaublich tolle Daten</td>
  </tr>
</table>
