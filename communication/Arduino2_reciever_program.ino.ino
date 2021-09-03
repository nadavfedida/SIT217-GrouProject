//For serial receive.
constbyte numChars = 30;
char receivedChars[numChars]; // an array to store the received data
String received; //The data as a string
boolean newData = false;
voidsetup() {
  Serial.begin(9600); // Starts the serial communication

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
} voidloop() {
  Serial.println("hello from arduino!");
  delay(1000);
  recvWithEndMarker();
  if (newData == true)
  {
    String instruction = received.substring(0, 5);
    Serial.println(instruction);
    if (instruction == "hello")
    {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
  }
}
delay(100);                       // wait for a second
digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by makingthe voltage LOW
}
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
      ndx = 0; newData = true;
    }
  }
}
