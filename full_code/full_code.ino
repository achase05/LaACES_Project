#include <SparkFun_Si7021_Breakout_Library.h>

#include <SPI.h>
#include "Adafruit_MAX31855.h"
#include <NewPing.h>
#include <Wire.h>

// thermo
// Default connection is using software SPI, but comment and uncomment one of
// the two examples below to switch between software SPI and hardware SPI:

// Example creating a thermocouple instance with software SPI on any three
// digital IO pins.
#define MAXDO   3
#define MAXCS   5
#define MAXCLK  2

// ping
#define TRIGGER_PIN 6
#define ECHO_PIN 7
#define MAX_DISTANCE 300
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

//LED lights

//LED 1
int redPin1 = 24;
int greenPin1 = 25;
int bluePin1 = 26;

//LED 2
int redPin2 = 5;
int greenPin2 = 6;
int bluePin2 = 7;

//LED 3
int redPin3 = 9;
int greenPin3 = 10;
int bluePin3 = 11;

//LED 4
int redPin4 = 13;
int greenPin4 = 14;
int bluePin4 = 15;

//LED 5
int redPin5 = 17;
int greenPin5 = 18;
int bluePin5 = 19;

// humidity
float humidity = 0;
float tempf = 0;

int power = A3;
int GND = A2;

Weather sensor;

// initialize the Thermocouple
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

// Example creating a thermocouple instance with hardware SPI
// on a given CS pin.
//#define MAXCS   10
//Adafruit_MAX31855 thermocouple(MAXCS);

void setup(){
  Serial.begin(9600);
  pinMode(power, HIGH);
  pinMode(GND, OUTPUT);

  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);

  digitalWrite(power, HIGH);
  digitalWrite(GND, LOW);
  sensor.begin();
  while (!Serial); // wait for Serial on Leonardo/Zero, etc
  
  Serial.println("MAX31855 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop(){
  //Ping Sensor
  printPing();
  Serial.println();
  
  //Humidity Sensor
  printHumTemp();
  Serial.println();
  
  //Thermocouple
  printTemp();
  Serial.println();
  Serial.println();

  setColor(redPin1, greenPin1, bluePin1, 0, 0, 255); //red
  delay(3000);
  setColor(redPin1, greenPin1, bluePin1, 255, 0, 255); //purple
  delay(3000);
  setColor(redPin1, greenPin1, bluePin1, 255, 0, 0); //blue

  Serial.println();
  
  delay(3000);
}


//Ping sensor value display
void printPing(){
  Serial.println("Readings from Ping Sensor");

  //Pingin microseconds
  Serial.println("Microseconds: ");
  Serial.print(sonar.ping());
  Serial.print("us");
}

/*void getWeather(){
  humidity = sensor.getRH();
  tempf = sensor.getTempF();  
}*/

//Humidity sensor value display
void printHumTemp(){
  Serial.println("Readings from Humidity Sensor");

  //Humidity in percent
  Serial.println("Humidity: ");
  Serial.print(sensor.getRH());
  Serial.print("%");

  //Temperature in Farenheit
  Serial.println("Temperature: ");
  Serial.print(sensor.getTempF());
  Serial.print(" F");
}

//Thermocouple value display
void printTemp(){
  Serial.println("Readings from Thermocouple");

  //Temperature in Farenheit
  Serial.println("Temperature (F): ");
  Serial.print(thermocouple.readFarenheit());
  Serial.print(" F");

  //Temperature in Celsius
  Serial.println("Temperature (C): ");
  Serial.print(thermocouple.readCelsius());
  Serial.print(" C");
}

//Sets pin color for LED
//Takes in the pin that will be lit
//Takes RGB values
void setColor(int redPin, int greenPin, int bluePin, int red, int green, int blue){
  //Write values to LED light
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
