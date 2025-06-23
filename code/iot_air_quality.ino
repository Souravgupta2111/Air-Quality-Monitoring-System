#include "arduino_secrets.h"
#include "thingProperties.h"
#include "DHT.h"

#define DHTpin 4
#define DHTTYPE DHT11
DHT dht(DHTpin,DHTTYPE);
int sensor = A0;

void setup() {
  Serial.begin(9600);
  delay(2000); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  dht.begin();
  delay(2000); // Allow sensor to stabilize
}

void loop() {
  ArduinoCloud.update();
  float hm = dht.readHumidity();
  float temp = dht.readTemperature();
  int airqualityvalue = analogRead(sensor);
  Serial.print("Humidity: ");
  Serial.println(hm);
  Serial.print("Temperature: ");
  Serial.println(temp);
  Serial.print("Air Quality: ");
  Serial.println(airqualityvalue);

  humidity = hm;
  temperature = temp;
  airquality = airqualityvalue;

  message = "Temperature = " + String(temperature) + " Humidity = " + String(humidity) + " Air Quality = " + String(airqualityvalue);
  delay(2000); // Delay between readings
}

void onTemperatureChange() { 
 } /* Since Humidity is READ_WRITE variable, onHumidityChange() is executed every time a new value is received from IoT Cloud. */ 
void onHumidityChange() { 
 }/* Since Airquality is READ_WRITE variable, onAirqualityChange() is executed every time a new value is received from IoT Cloud. */
void onAirqualityChange() { 
 } /* Since Message is READ_WRITE variable, onMessageChange() is executed every time a new value is received from IoT Cloud. */
void onMessageChange() { 
}
