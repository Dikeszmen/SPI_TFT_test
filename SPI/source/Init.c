#include <stdio.h>
#include <stdlib.h>


int Init(int *speed,int *fd)
{

    wiringPiSetup();
    /**SYSLOG has to set correctly*/
    openlog(NULL,LOG_PID,LOG_LOCAL1);
    int retValue;
    pinMode(SCK,OUTPUT);
    pinMode(MOSI,OUTPUT);
    pinMode(CHIP0,OUTPUT);
    pinMode(CHIP1,OUTPUT);

    digitalWrite(CHIP0,HIGH);
    digitalWrite(CHIP1,HIGH);
        if(*fd=wiringPiSPISetup(CHIP0,*speed))
            retValue=CHIP0;
        else if(*fd=wiringPiSPISetup(CHIP1,*speed))
               retValue=CHIP1;
        else
        {
        perror("No CHIP Select\n");
            return -1;
        }

    return 0;
}

int sendDatas(int *CS,char *message)
{
    digitalWrite(*CS,0);
    int len;
    char *buffer;
}
