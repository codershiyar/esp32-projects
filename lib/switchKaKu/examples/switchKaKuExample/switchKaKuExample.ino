
/* This example switches KaKu device op pin 4
 * every 5 seconds on/off
 * device id = 1 and group id = 1
 * unique id of the simulated transmitter is 1234
 */

#include "switchKaKu.h"
#define TRANSMITTERID1 14881086
#define TRANSMITTERID2 10469306

void setup() {
  Serial.begin(115200);
}

void loop() {
  switchKaku(4, TRANSMITTERID2, 1, 4, true, 3, 8); //switch group 1, device 4, dimlevel 8 (max 15), repeat 3, on
  switchKaku(4, TRANSMITTERID1, 1, 1, true, 3); //switch group 1, device 1, repeat 3, on
  delay(5000);
  switchKaku(4, TRANSMITTERID2, 1, 4, false, 3); //switch group 1, device 4, repeat 3, off
  switchKaku(4, TRANSMITTERID1, 1, 1, false, 3); //switch group 1, device 1, repeat 3, off
  delay(5000);
}

