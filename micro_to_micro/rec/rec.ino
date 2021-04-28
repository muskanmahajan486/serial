/* 
 author : danu Andrean
 note : receiver

*/

#include <SoftwareSerial.h>
SoftwareSerial ser(D6,D5);

int starts = 0;
int checksum = 0;

void setup() {
  ser.begin(9600);
  Serial.begin(9600);
}
 
void loop() {
  String content = "";
  String content_check = "";
  
  if (ser.available()) {
    while (ser.available()) {
      
      char data = (char)ser.read() ;
      Serial.print(starts);//
      if(data == '|'){
        checksum = 1;
      }
      //start
      if(data=='*')
        starts =1;
       //end
      else if(data =='#'){
        starts =0;
        checksum = 0;
        break;
      }
        
      else if(starts == 1){
        if(checksum == 0 ){
          content += data;
        }
        else{
          content_check += data; 
        }
        
      }
      
    }
  }
  Serial.println(content);
  delay(1200);
  
  content = "";
  content_check = "";
}
