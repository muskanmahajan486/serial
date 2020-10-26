#ifndef SERIAL
#define SERIAL

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>     /* atoi */

char serialPortFilename[] = "/dev/ttyUSB1";

class Serial{
   public :
   FILE *serPort ;
   char readBuffer[1024];
   int data_gyro;
   int init();
   int gyro();
};

int Serial::init(){
   

   this->serPort= fopen(serialPortFilename, "r");

	if (serPort == NULL)
	{
		printf("USB ERROR");	
		return 0;
	}

	// printf(serialPortFilename);
	// printf(":\n");
   
}
int Serial::gyro(){

   
   memset(this->readBuffer, 0, 1024);
   fread(this->readBuffer, sizeof(char),1024,this->serPort);
   if(sizeof(this->readBuffer) != 0)
   {
      // printf(readBuffer);
      this->data_gyro= atoi(this->readBuffer);
   }
	
   return this->data_gyro;
}

#endif
