#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
#include <wiringPiSPI.h>
#include <linux/spi/spidev.h>
#include <wiringPi.h>
#include <syslog.h>
#include <string.h>
#define SCK 14
#define MOSI 12
#define CHIP0 10
#define CHIP1 11
#define LOW 0
#define HIGH

/**

in your program. Programs need to be linked with -lwiringPi as usual.

Functions available:

    int wiringPiSPISetup (int channel, int speed) ;

This is the way to initialise a channel (The Pi has 2 channels; 0 and 1).
The speed parameter is an integer in the range 500,000 through 32,000,000 and represents the SPI clock speed in Hz.

The returned value is the Linux file-descriptor for the device, or -1 on error. If an error has happened, you may use the standard errno global variable to see why.

    int wiringPiSPIDataRW (int channel, unsigned char *data, int len) ;

This performs a simultaneous write/read transaction over the selected SPI bus. Data that was in your buffer is overwritten by data returned from the SPI bus.

That’s all there is in the helper library. It is possible to do simple read and writes over the SPI bus using the standard read() and write() system calls though
 – write() may be better to use for sending data to chains of shift registers, or those LED strings where you send RGB triplets of data.
 Devices such as A/D and D/A converters usually need to perform a concurrent write/read transaction to work.*/
typedef struct Serial_SPI{
    int dlen;
    int data;
    int cmd;

}SPI_package;

int Init(int *speed,int *fd);

#endif // INIT_H_INCLUDED
