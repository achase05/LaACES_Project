#include <NewPing.h>

#define TRIGGER_PIN 6
#define ECHO_PIN 7
#define MAX_DISTANCE 300

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
  Serial.begin(9600);
  }

void loop(){
  delay(50);
  Serial.print("Microseconds: ");
  Serial.print(sonar.ping());
  Serial.println("us");
  }
