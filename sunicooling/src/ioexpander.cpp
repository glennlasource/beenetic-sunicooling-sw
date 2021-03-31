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
  | ioexpander.cpp
  |________________________________________________________________________
*/
#include "ioexpander.h"

void ioexpander_initialize(){
  //Init of first ioexpander
  PCA8574 pca8574n1(PCA8574_I2C_ADDR, I2C_SDA, I2C_SCL);
	ioexpander_setPin(pca8574n1, P00, OUTPUT, HIGH);
  ioexpander_setPin(pca8574n1, P01, OUTPUT, HIGH);
  ioexpander_setPin(pca8574n1, P02, OUTPUT, HIGH);
  ioexpander_setPin(pca8574n1, P03, OUTPUT, HIGH);
  ioexpander_setPin(pca8574n1, P04, OUTPUT, HIGH);
  ioexpander_setPin(pca8574n1, P05, OUTPUT, HIGH);
  ioexpander_setPin(pca8574n1, P06, OUTPUT, HIGH);
  ioexpander_setPin(pca8574n1, P06, OUTPUT, HIGH);
}

void ioexpander_setPin(PCA8574 pca8574, uint8_t pin, uint8_t type, uint8_t start_value){
  pca8574.pinMode(pin, type, start_value);
}

bool ioexpander_write(PCA8574 pca8574, uint8_t pin, uint8_t value){
  #ifdef Verbose
  Serial.print("Writing ");
  Serial.print(value);
  Serial.print(" to pin");
  Serial.println(int(pin));
  #endif
  return pca8574.digitalWrite(pin, value);
}

uint8_t ioexpander_read(PCA8574 pca8574, uint8_t pin){
  #ifdef Verbose
  Serial.print("Reading ");
  Serial.print(value);
  Serial.print(" from pin");
  Serial.println(int(pin));
  #endif
  return pca8574.digitalRead(pin);
}

