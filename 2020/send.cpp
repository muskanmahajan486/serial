/* 
 author : danu Andrean
 note : transmitter

*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
using namespace std;

char serialPortFilename[] = "/dev/ttyUSB0";

int main()
{
   while(1){
      FILE *serPort = fopen(serialPortFilename, "w");

      if (serPort == NULL)
      {
         printf("ERROR");	
         return 0;
      }
      string arduino="1,90,11";

      for(int i = 0; i<arduino.length();i++){
         char send =arduino[i];
         fwrite(&send, sizeof(send),1, serPort);
      }
      // sleep(1);
      fclose(serPort);
      // sleep(1);
      cout<<arduino<<endl; 

   }
	return 0;
   
}
