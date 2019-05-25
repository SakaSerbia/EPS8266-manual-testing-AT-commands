// ESP8266 manual testing AT commands

void setup()
{
  // serial port used for debugging
  Serial.begin(115200); 
  // your ESP's baud rate might be different
  Serial1.begin(9600);  
}
 
void loop()
{
  // check if the ESP is sending a message
  if(Serial1.available())  
  {
    while(Serial1.available())
    {
      // read the next character
      int c = Serial1.read(); 
      // writes data to the serial monitor
      Serial.write((char)c);  
    }
  }
 
  if(Serial.available())
  {
    // wait to let all the input command in the serial buffer
    delay(10);

    // read the input command in a string
    String cmd = "";
    while(Serial.available())
    {
      cmd += (char)Serial.read();
    }

    // print the command and send it to the ESP
    Serial.println();
    Serial.print(">>>> ");
    Serial.println(cmd);

    // send the read character to the ESP
    Serial1.print(cmd);
  }
}
