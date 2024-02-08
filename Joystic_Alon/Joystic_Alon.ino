/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservoX;  // create servo object to control a servo
Servo myservoY;  // create servo object to control a servo

int potpinX = A0;  // analog pin used to connect the potentiometer
int potpinY = A1;  // analog pin used to connect the potentiometer
int valX;    // variable to read the value from the analog pin
int valY;    // variable to read the value from the analog pin

void setup() {
  myservoX.attach(9);  // attaches the servo on pin 9 to the servo object
  myservoY.attach(10);  // attaches the servo on pin 10 to the servo object
  Serial.begin(9600);
}

void loop() {
  valX = analogRead(potpinX);            // reads the value of the potentiometer (value between 0 and 1023)
  valX = map(valX, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservoX.write(valX);                  // sets the servo position according to the scaled value
  
  valY = analogRead(potpinY);            // reads the value of the potentiometer (value between 0 and 1023)
  valY = map(valY, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservoY.write(valY);                  // sets the servo position according to the scaled value

  delay(15);    // waits for the servo to get there
 
  Serial.print("X-value:");
  Serial.print(valX);
  Serial.print(",");
  Serial.print("Y-value:");
  Serial.println(valY);


 
}
