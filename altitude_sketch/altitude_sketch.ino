#include <Wire.h>
#include <MS5611.h>

MS5611 sensor;

double referencePressure;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Initialize MS5611 Sensor");
  Serial.println("test 1");
  //sensor.begin();
  Serial.println("Test 2");
  /*if(sensor.begin()){
    Serial.println("Sensor found.");
    delay(500);
  }*/

  referencePressure = sensor.readPressure();
  Serial.println("Test 3");
  checkSettings();
  Serial.println("Test 4");
}

void checkSettings(){
  Serial.print("Oversampling: ");
  Serial.println(sensor.getOversampling());  
}

void loop() {
  Serial.println("Test");
  // put your main code here, to run repeatedly:
  uint32_t rawTemp = sensor.readRawTemperature();
  uint32_t rawPressure = sensor.readRawPressure();

  double realTemp = sensor.readTemperature();
  long realPressure = sensor.readPressure();

  float absoluteAltitude = sensor.getAltitude(realPressure);
  float relativeAltitude = sensor.getAltitude(realPressure, referencePressure);

  Serial.println("--");

  Serial.print(" rawTemp = ");
  Serial.print(rawTemp);
  Serial.print(", realTemp = ");
  Serial.print(realTemp);
  Serial.println(" *C");

  Serial.print(" rawPressure = ");
  Serial.print(rawPressure);
  Serial.print(", realPressure = ");
  Serial.print(realPressure);
  Serial.println(" Pa");

  Serial.print(" absoluteAltitude = ");
  Serial.print(absoluteAltitude);
  Serial.print(" m, relativeAltitude = ");
  Serial.print(relativeAltitude);
  Serial.println(" m");

  delay(1000);
}
