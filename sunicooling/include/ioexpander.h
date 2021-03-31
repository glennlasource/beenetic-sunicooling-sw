/* ________________________________________________________________________
  |
  | Projet SuniCooling BY SUNIBRAIN
  |________________________________________________________________________
  |
  |  (ESP32)
  |  ------------------------
  |  Glenn Le Bouhart - BEENETIC Systems SAS
  |  glenn.lebouhart@beenetic.com
  |________________________________________________________________________
  |
  | ioexpander.h
  |________________________________________________________________________
*/
#include "Arduino.h"
#include "PCA8574.h"
#include "globals.h"

                  //Peripherics -- PCA8574 
#define P00  	P0  //P00 -- PCA8574's pin0
#define P01  	P1  //P01 -- PCA8574's pin1
#define P02  	P2  //P02 -- PCA8574's pin2
#define P03  	P3  //P03 -- PCA8574's pin3
#define P04  	P4  //P04 -- PCA8574's pin4
#define P05  	P5  //P05 -- PCA8574's pin5
#define P06  	P6  //P06 -- PCA8574's pin6
#define P07  	P7  //P07 -- PCA8574's pin7

#define PCA8574_I2C_ADDR 0x38

void ioexpander_initialize();



