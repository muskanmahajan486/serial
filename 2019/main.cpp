#include "mySerial.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;



int  main(void)
{

    mySerial serial("/dev/ttyUSB0",9600);
    while(1){

    // One Byte At the time
     //serial.Send(128);
    char * c="0";
    int len = strlen(c);
     

    // An array of byte
    // unsigned char  dataArray[] = { 142,0};
    serial.Send(5);

    // Or a string
    //serial.Send("this is it\r\n");
    serial.Receive(c,len);
    // printf(serial.Receive(mySerial,1024));
   
    }
    return 0;

}

