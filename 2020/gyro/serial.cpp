#include "../../../Framework/include/serial.h"
#include <stdio.h>
#include "serial.h"
#include <iostream>

int main(){
   Serial serial;
   serial.init();
   while(1){

      int data = serial.gyro();
      // printf("%d \n", data);
      std::cout<<data<<std::endl;
      // sleep(1);
   }
}
