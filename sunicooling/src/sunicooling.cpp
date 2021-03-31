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
  | sunicooling.cpp
  |________________________________________________________________________
*/
#include <Arduino.h>
#include "sunicooling.h"

/*****************************************************************************/
#include "PCA8574.h"

// For arduino uno only pin 1 and 2 are interrupted
#define PCA1_INT 34

// Function interrupt
void keyPressedOnPCA8574();

// Set i2c address
PCA8574 pca8574(0x38, PCA1_INT, keyPressedOnPCA8574);
unsigned long timeElapsed;
void setup()
{
	Serial.begin(115200);

	pca8574.pinMode(P0, OUTPUT, HIGH);
	pca8574.pinMode(P1, OUTPUT, HIGH);
	pca8574.pinMode(P2, OUTPUT, HIGH);
	pca8574.pinMode(P3, OUTPUT, HIGH);
  pca8574.pinMode(P4, OUTPUT, HIGH);
	pca8574.pinMode(P5, OUTPUT, HIGH);
	pca8574.pinMode(P6, OUTPUT);
  pca8574.pinMode(P7, OUTPUT);

	Serial.print("Init pca8574...");
	if (pca8574.begin()){
		Serial.println("OK");
	}else{
		Serial.println("KO");
	}

	timeElapsed = millis();
}
unsigned long lastSendTime = 0;        // last send time
unsigned long interval = 4000;          // interval between sends

bool startVal = HIGH;

bool keyPressed = false;
void loop()
{
  if (millis() - lastSendTime > interval){
    if (startVal==HIGH) {
				startVal = LOW;
			}else{
				startVal = HIGH;
			}
		lastSendTime = millis();
    pca8574.digitalWrite(P0, startVal);
    pca8574.digitalWrite(P1, startVal);
    pca8574.digitalWrite(P2, startVal);
    pca8574.digitalWrite(P3, startVal);
    pca8574.digitalWrite(P4, startVal);
    pca8574.digitalWrite(P5, startVal);
    Serial.print("State : ");
		Serial.println(startVal);
  }
}

void keyPressedOnPCA8574(){
	// Interrupt called (No Serial no read no wire in this function, and DEBUG disabled on PCF library)
	 keyPressed = true;
}