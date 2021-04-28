#include <SoftwareSerial.h>
SoftwareSerial ser(D6,D5);

int starts = 0;
int checksum = 0;
int bypass = 0;

void setup() {
  ser.begin(9600);
  Serial.begin(9600);
}
 
void loop() {
  String data_decode ="";
  String content = "";
  String content_check = "";
  
  if (ser.available()) {
    while (ser.available()) {
      
      char data = (char)ser.read() ;
//      Serial.print(starts);//
      if(data == '|'){
        checksum = 1;
      }
      //start
      if(data=='*')
        starts =1;
       //end
      else if(data =='#'){
        
        Serial.println("check");
        if(content != content_check){
          content = "";
          content_check = "";
        }
        data_decode = content;
        starts =0;
        checksum = 0;
        bypass =0;
        break;
      }
        
      else if(starts == 1){
        if(checksum == 0 ){
          content += data;
        }
        else{
          if( bypass == 0)
             bypass =1;
          else
            content_check += data; 
          
        }
      }
    }
  }
  Serial.println(data_decode);
  delay(100);
  
  content = "";
  content_check = "";
}
