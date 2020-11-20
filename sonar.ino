#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

const int trigPin = 10;
const int echoPin = 11;
// Variables for the duration and distance
long timer;
int dist;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  lcd.begin(16,2);
}
void loop() {
  dist = calculatedist();// Calls a function for calculating the dist measured
  lcd.print(dist);
  lcd.print(" cms");
  delay(350);
  lcd.clear();
}

// Function for calculating the dist measured by the Ultrasonic sensor
int calculatedist(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  timer = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  dist=(timer*0.0340)/2;
  return dist;
}
