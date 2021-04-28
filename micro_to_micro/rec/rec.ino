/* 
 author : danu Andrean
 note : receiver

*/

#include <SoftwareSerial.h>
SoftwareSerial ser(D6,D5);

int starts = 0;
String len = "";

void setup() {
  ser.begin(9600);
  Serial.begin(9600);
}
 
void loop() {
  String content = "";
  if (ser.available()) {
    while (ser.available()) {
      
      char data = (char)ser.read() ;
//      Serial.print(starts);/
      
      if(data=='*')
        starts =1;
        
      else if(data =='#'){
          starts =0;
          break;
        }
        
      else if(starts == 1){
        if(input == 0)
          len + = data;
        
        if(data == '/')
          input =1;
        
        else if(input == 1)
          content += data;
      }
      
    }
  }
  Serial.println(content);
  delay(3000);
  content = "";
}
