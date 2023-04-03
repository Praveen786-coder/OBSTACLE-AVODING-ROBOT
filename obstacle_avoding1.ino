#include <Servo.h>
int trigPin = 13;    
int echoPin = 7;
int distance;
int Input1=8;
int Input2=9;
int Input4=11;
int Input3=10;
long duration;
Servo myservo; 
void setup() {
  Serial.begin(9600);      
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(12); 
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(Input4, OUTPUT);
  pinMode(Input3, OUTPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration*0.034/2;   
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance>20) 
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(Input4, HIGH);
    digitalWrite(Input3, LOW);
    delay(1000);  
    myservo.write(90);
    
  }
  else if(distance<19)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);      //  stop
    digitalWrite(Input4, LOW);
    digitalWrite(Input3, LOW);
    delay(350);
    
    myservo.write(0);
    delay(500);
    myservo.write(180);
    delay(500);
    myservo.write(90);
    delay(500);
    
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(Input4, LOW);    // BACKWARD
    digitalWrite(Input3,HIGH);
    delay(1000);
  
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(Input4, LOW);
    digitalWrite(Input3, LOW);     // STOP
    delay(350);
    
    
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(Input4, LOW);   // TURN RIGHT
    digitalWrite(Input3, HIGH);
    delay(1000);
    
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);      //  stop
    digitalWrite(Input4, LOW);
    digitalWrite(Input3, LOW);
    delay(350);
    
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);      //  TURN LEFT
    digitalWrite(Input4, HIGH);
    digitalWrite(Input3, LOW);
    delay(1000);
  }    
}
