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
  String len= (String)strlen(data);
  String key[]={"ss","ff","dd"};
  ser.write("*");
  ser.write(data);/////
  ser.write("|");
  ser.write(data);
  ser.write("#");
  delay(1000);
}
