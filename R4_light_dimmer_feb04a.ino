#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/de7f3672-c042-4f5a-8b7a-97dfedfe8af9 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  CloudDimmedLight light_intensity;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/
#include "Arduino_LED_Matrix.h"
#include "thingProperties.h"

ArduinoLEDMatrix matrix;
int relay = 4;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  pinMode(relay, OUTPUT);

  matrix.begin();

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here
  if (light_intensity.getSwitch() == 1) {
    digitalWrite(relay, HIGH);
  };
  if (light_intensity.getSwitch() == 0) {
    digitalWrite(relay, LOW);
  };
  delay(40);
}

/*
  Since LightIntensity is READ_WRITE variable, onLightIntensityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightIntensityChange()  {
  // Add your code here to act upon LightIntensity change
  Serial.println(light_intensity.getBrightness());
  Serial.println(light_intensity.getSwitch());
}
