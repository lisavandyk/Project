#ifndef PRAC4_H
#define PRAC4_H

//Includes
#include <wiringPi.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPiSPI.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#include <iostream>
#include <mcp3004.h>

//Define buttons
#define BUFFER_SIZE 1000000

//Define LEDS

//SPI Settings
#define SPI_CHAN 0
#define SPI_SPEED 500000
#define BASE 100

//Function definitions
int setup_gpio(void);
int main(void);
int lastInt = 0;
int interruptTime;

#endif
