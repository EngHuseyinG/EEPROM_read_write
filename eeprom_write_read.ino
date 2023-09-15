/*
   EEPROM Write

   Stores random values into the EEPROM.
   These values will stay in the EEPROM when the board is
   turned off and may be retrieved later by another sketch.
*/

#include "EEPROM.h"
#define EEPROM_SIZE 64
// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int count = 0 ;
bool _bool = false;
#define EEPROM_SIZE 64
void setup()
{
Serial.begin(115200);
  while (!Serial) { }
  Serial.println("start...");
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(1000000);
  }
delay(1000);
count = EEPROM.read(10) ;
_bool = EEPROM.read(11);
Serial.println(EEPROM.read(10));
Serial.println(EEPROM.read(11));
Serial.println(EEPROM.read(12));
delay(1000);
EEPROM.write( 10, count+1);
EEPROM.write(11, !_bool);
EEPROM.write(12, count+2);
EEPROM.commit();
}

void loop()
{

}
