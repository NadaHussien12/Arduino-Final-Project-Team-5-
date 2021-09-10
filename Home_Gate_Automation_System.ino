//Declaration and initialization for some variables: 
#define MOTOR1 8
#define MOTOR2 9
const int buzzer = 6;



void setup()
{
  pinMode(buzzer,OUTPUT);
  pinMode(MOTOR1,OUTPUT);
  pinMode(MOTOR2,OUTPUT);
  Serial.begin(9600);
}

void loop()
{

//Motor Code:
  digitalWrite(MOTOR1,HIGH);
  digitalWrite(MOTOR2,LOW);
  

//Buzzer Code:

  // Send 1KHz sound signal for 1 sec.
  tone(buzzer, 1000); 
  delay(1000); 

  //Stop the sound for 2 secs.
  noTone(buzzer);
  delay(2000);   
}
