#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <pins_arduino.h>


// LED input
int LEDlight=4;
//int LEDin=4;

//Right motor
int enableRightMotor=5; 
int rightMotorPin1=7;
int rightMotorPin2=8;

//Left motor
int enableLeftMotor=6;
int leftMotorPin1=9;
int leftMotorPin2=10;


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(LEDlight,OUTPUT);
//  pinMode(LEDin,INPUT);

  pinMode(enableRightMotor,OUTPUT);
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin2,OUTPUT);
  
  pinMode(enableLeftMotor,OUTPUT);
  pinMode(leftMotorPin1,OUTPUT);
  pinMode(leftMotorPin2,OUTPUT);

  rotateMotor(0,0);   
    
  Dabble.begin(9600, 2, 3);

}

void loop()
{
  int rightMotorSpeed=0;
  int leftMotorSpeed=0;
  Dabble.processInput();
  
if (GamePad.isTrianglePressed())
  {
    if (digitalRead(LEDlight) == HIGH)
    {    
      digitalWrite(LEDlight, LOW);    // turn the LED off by making the voltage LOW
      return;
    }
    else if(digitalRead(LEDlight) == LOW)
    {
      digitalWrite(LEDlight, HIGH);   // turn the LED on (HIGH is the voltage level)
      return;
    }

  }

  
  
  
  if (GamePad.isUpPressed())
  {
    rightMotorSpeed = 150;//255
    leftMotorSpeed = 150;//255
    Serial.println("Up");

  }

  if (GamePad.isDownPressed())
  {
    Serial.println("down");
    rightMotorSpeed = -150;//-255
    leftMotorSpeed = -150;//-255
    
  }

  if (GamePad.isLeftPressed())
  {
    Serial.println("left");
    rightMotorSpeed = 100; // 50
    leftMotorSpeed = 150;//255
  }

  if (GamePad.isRightPressed())
  {
    Serial.println("right");
    rightMotorSpeed = 150;//255
    leftMotorSpeed = 100; // 50
  }

  rotateMotor(rightMotorSpeed, leftMotorSpeed);
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed >= 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed >= 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }

  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}
