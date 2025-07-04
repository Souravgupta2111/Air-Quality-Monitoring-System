// This file is auto-generated when using Arduino IoT Cloud.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "    ";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onMessageChange();
void onAirqualityChange();
void onHumidityChange();
void onTemperatureChange();

String message;
CloudPercentage airquality;
CloudPercentage humidity;
CloudTemperature temperature;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(message, READWRITE, ON_CHANGE, onMessageChange);
  ArduinoCloud.addProperty(airquality, READWRITE, ON_CHANGE, onAirqualityChange);
  ArduinoCloud.addProperty(humidity, READWRITE, ON_CHANGE, onHumidityChange);
  ArduinoCloud.addProperty(temperature, READWRITE, ON_CHANGE, onTemperatureChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
  
