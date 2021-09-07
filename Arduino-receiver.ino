//For serial receive.
const byte numChars = 30;
char receivedChars[numChars]; // an array to store the received data
String received; //The data as a string
boolean newData = false;
#define CUSTOM_SETTINGS

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
  Serial.begin(9600); // Starts the serial communication
  pinMode(enableRightMotor,OUTPUT);
  pinMode(rightMotorPin1,OUTPUT);
  pinMode(rightMotorPin2,OUTPUT);

  pinMode(enableLeftMotor,OUTPUT);
  pinMode(leftMotorPin1,OUTPUT);
  pinMode(leftMotorPin2,OUTPUT);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //Serial.println("hello from arduino!");
  int rightMotorSpeed=0;
  int leftMotorSpeed=0;
  recvWithEndMarker();
   if (newData == true)
   {
      String instruction = received.substring(0,5);
      Serial.println(instruction);
      if (instruction == "right")
      {
        rightMotorSpeed = -100; // 50
        leftMotorSpeed = 150;//255
      }
      if (instruction == "upppp")
      {
        rightMotorSpeed = -150;//255
        leftMotorSpeed = 150;//255
      }
      if(instruction == "downn")
      {
        rightMotorSpeed = 150;//-255
        leftMotorSpeed = -150;//-255
      }
      if (instruction == "leftt")
      {
        rightMotorSpeed = -150;//255
        leftMotorSpeed = 100; // 50
      }
      if (instruction == "squar")
      {
        rightMotorSpeed = 0;//255
        leftMotorSpeed = 0; // 50
      }
     
      rotateMotor(rightMotorSpeed, leftMotorSpeed);
      newData = false;
   }  
}

void recvWithEndMarker() 
{
 static byte ndx = 0;
 char endMarker = '\n';
 char rc;
 
 while (Serial.available() > 0 && newData == false) 
 {
  rc = Serial.read();

  if (rc != endMarker) 
  {
    receivedChars[ndx] = rc;
    ndx++;
    if (ndx >= numChars) 
    {
      ndx = numChars - 1;
    }
 }
 else 
  {
  receivedChars[ndx] = '\0'; // terminate the string
  received = String(receivedChars);
  ndx = 0;
  newData = true;
  }
 }
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
