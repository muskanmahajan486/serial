void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 9600 baud
}

void loop() {
 while(Serial.available() !=0)
  {
    int data = Serial.read();
    //Serial.println(char(data));
    Serial.write(data);
  }
}
