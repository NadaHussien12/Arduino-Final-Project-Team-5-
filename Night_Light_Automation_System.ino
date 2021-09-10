//Declaration and initialization of some variables:
#define LDR A0
#define LED 13
#include <Servo.h>

// constants won't change
const int TRIG_PIN  = 6;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN  = 7;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int SERVO_PIN = 9; // Arduino pin connected to Servo Motor's pin
const int DISTANCE_THRESHOLD = 50; // centimeters
int LDR_VAL; 
Servo servo; // create servo object to control a servo

// variables will change:
float duration_us, distance_cm;

void setup()
{
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LDR,INPUT);
  pinMode(LED,OUTPUT);
  servo.attach(SERVO_PIN);   // attaches the servo on pin 9 to the servo object
  servo.write(0);
}

void loop()
{
  digitalWrite(LED,LOW);
  LDR_VAL= analogRead(LDR);
  Serial.print("LDR VALUE = ");
  Serial.println(LDR_VAL);
  delay(1000);

  
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;
  servo.write(180); // rotate servo motor to 90 degree
  delay(500);
  servo.write(0);  // rotate servo motor to 0 degree
    
   
  
  
  if(LDR_VAL>1000)
  {
    Serial.println("Day");
    delay(1000);
  }
  else
  {
    Serial.println("At night");
    delay(1000);
   if(distance_cm < DISTANCE_THRESHOLD)
   {
    Serial.print("distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
    delay(1000);
    Serial.println("There is someone in the room");
    digitalWrite(LED,HIGH);
    delay(3000);
    }
    else
    {
      Serial.println("Nobody in the room");
    }
  } 
}
