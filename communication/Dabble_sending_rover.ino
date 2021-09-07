#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

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
  if (GamePad.isUpPressed())
  {
    rightMotorSpeed = 150;//255
    leftMotorSpeed = 150;//255
    Serial.println("upppp");
    //delay(1000);
    return;

  }
//  if (Serial.read() == "e")
//    {
//      Serial.println("Forward");
//      rightMotorSpeed = -150;//255
//      leftMotorSpeed = 150;//255
//      delay(1000);
//      return;
//    }

  if (GamePad.isDownPressed())
  {
    Serial.println("downn");
    rightMotorSpeed = -150;//-255
    leftMotorSpeed = -150;//-255
    //delay(1000);
    return;
    
  }
  if (GamePad.isSquarePressed())
  {
    Serial.println("squar");
    rightMotorSpeed = 0;//-255
    leftMotorSpeed = 0;//-255
    //delay(1000);
    return;
    
  }
  if (GamePad.isLeftPressed())
  {
    Serial.println("leftt");
    rightMotorSpeed = 100; // 50
    leftMotorSpeed = 150;//255
    //delay(1000);
    return;
  }

  if (GamePad.isRightPressed())
  {
    Serial.println("right");
    rightMotorSpeed = 150;//255
    leftMotorSpeed = 100; // 50
   //delay(1000);
    return;
  }
  if (GamePad.isCirclePressed())
  {
    Serial.println("circl");
    rightMotorSpeed = 255;//255
    leftMotorSpeed = -255; // 50
    //delay(1000);
    return;
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
