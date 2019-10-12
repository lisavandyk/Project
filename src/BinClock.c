/*
 * BinClock.c
 * Jarrod Olivier
 * Modified for EEE3095S/3096S by Keegan Crankshaw
 * August 2019
 * 
 * <JNSJOH021> <VDYLIS001>
 * 16/08/2019
*/

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h> //For printf functions
#include <stdlib.h> // For system functions
#include<softPwm.h>//for pwm functions
#include <signal.h> //For keyboard interrupt

#include "BinClock.h"
#include "CurrentTime.h"

//Global variables
int hours, mins, secs;
long lastInterruptTime = 0; //Used for button debounce
int RTC; //Holds the RTC instance
int HH,MM,SS;

void initGPIO(void){
	
	printf("Setting up\n");
	//wiringPiSetup();
	
	
}

int main(void){
	initGPIO();
	//signal(SIGINT,cleanGPIO);
	//Set random time (3:04PM)
	//You can comment this file out later
	//wiringPiI2CWriteReg8(RTC, HOUR, 0x07);
	//wiringPiI2CWriteReg8(RTC, MIN, 0x00);
	//wiringPiI2CWriteReg8(RTC, SEC, 0x00);
	
	

	// Repeat this until we shut down
	for (;;){
		//Fetch the time from the RTC
		//Write your logic here
		hours = getHours();
		mins = getMins();
		secs = getSecs();

		//Function calls to toggle LEDs
		//Write your logic here
		
		
		
		// Print out the time we have stored on our RTC
		printf("The current time is: %d:%d:%d\n",hours,mins, secs);

		//using a delay to make our program "less CPU hungry"
		delay(1000); //milliseconds
	}
	return 0;
}

/*
 * Change the hour format to 12 hours
 */
int hFormat(int hours){
	/*formats to 12h*/
	if (hours >= 24){
		hours = 0;
	}
	else if (hours > 12){
		hours -= 12;
	}
	return (int)hours;
}

int hexCompensation(int units){
	/*Convert HEX or BCD value to DEC where 0x45 == 0d45 
	  This was created as the lighXXX functions which determine what GPIO pin to set HIGH/LOW
	  perform operations which work in base10 and not base16 (incorrect logic) 
	*/
	int unitsU = units%0x10;

	if (units >= 0x50){
		units = 50 + unitsU;
	}
	else if (units >= 0x40){
		units = 40 + unitsU;
	}
	else if (units >= 0x30){
		units = 30 + unitsU;
	}
	else if (units >= 0x20){
		units = 20 + unitsU;
	}
	else if (units >= 0x10){
		units = 10 + unitsU;
	}
	return units;
}

int decCompensation(int units){
	int unitsU = units%10;

	if (units >= 50){
		units = 0x50 + unitsU;
	}
	else if (units >= 40){
		units = 0x40 + unitsU;
	}
	else if (units >= 30){
		units = 0x30 + unitsU;
	}
	else if (units >= 20){
		units = 0x20 + unitsU;
	}
	else if (units >= 10){
		units = 0x10 + unitsU;
	}
	return units;
}
