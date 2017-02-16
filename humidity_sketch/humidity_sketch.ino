#include <SparkFun_Si7021_Breakout_Library.h>
#include <Wire.h>

float humidity = 0;
float tempf = 0;

int power = A3;
int GND = A2;

Weather sensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(power, HIGH);
  pinMode(GND, OUTPUT);

  digitalWrite(power, HIGH);
  digitalWrite(GND, LOW);

  sensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  getWeather();
  printInfor();
  delay(1000);
}

void getWeather(){
  humidity = sensor.getRH();

  tempf = sensor.getTempF();
}

void printInfo(){
  Serial.print("Temp:");
  Serial.print(tempf);
  Serial.print("F, ");

  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.println("%");
}
