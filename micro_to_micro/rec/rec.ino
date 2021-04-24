/* 
 author : danu Andrean
 note : receiver

*/

#include <SoftwareSerial.h>
SoftwareSerial ser(D6,D5);

void setup() {
  ser.begin(9600);
  Serial.begin(9600);
}
 
void loop() {
  String content = "";
  if (ser.available()) {
    while (ser.available()) {
      content += (char)ser.read();
    }
  }
  Serial.println(content);
  delay(1000);
  content = "";
}
