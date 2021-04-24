/* 
 author : danu Andrean
 note : transmiter

*/

#include <SoftwareSerial.h>
SoftwareSerial ser(D5,D6);
 
void setup() {
  ser.begin(9600);
  
}
 
void loop() {
  char *data="Danu Andrean";
  ser.write(data);
  delay(1000);
}
