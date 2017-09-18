#include <stdio.h>
#include <stdlib.h>
#include <linux/spi/spidev.h>
#include <wiringPiSPI.h>
#include <wiringPi.h>
#include <syslog.h>
#define SCK 14
#define MOSI 12
#define CHIP0 10
#define CHIP1 11
void Init(int *speed,int *fd)
{

    wiringPiSetup();
    /**SYSLOG has to set correctly*/
    openlog(NULL,LOG_PID,LOG_LOCAL1);

    pinMode(SCK,OUTPUT);
    pinMode(MOSI,OUTPUT);
    pinMode(CHIP0,OUTPUT);
    pinMode(CHIP1,OUTPUT);

        if(!(*fd=wiringPiSPISetup(CHIP0,speed)))
            syslog(LOG_ERR,"Chip select is not in pin 10\n");
        else if(!(*fd=wiringPiSPISetup(CHIP1,speed)))
                {
                    syslog(LOG_ERR,"Chip select is not in pin 11\n");
                    return -1;
                }
        wiringPiSP

        //speed channel  in frequency e.g. 50000 depends on slave(int)





}
