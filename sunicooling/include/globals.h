#define VERBOSE
#ifdef VERBOSE
#include "Arduino.h"
#endif

#ifdef VERBOSE
Serial.println("Debug active")
#else
Serial.println("Debug inactive")
#endif

#define I2C_SDA 25
#define I2C_SCL 26
