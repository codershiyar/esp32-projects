/*  Switch Klik aan/Klik uit switches transmitter
 *  Usage: switchKaku(int pin, unsigned long id, int group, int dev, bool state, int repeat)
 *  pin = pin number
 *  id = unique id of transmitter (max 4194303)
 *  group = between 1 and 4, 
 *  device = between 1 and 4, -1 switches the entire group
 *  state = true (on) or false (off)
 *  repeat = transmit repeats
 */
 
#include "Arduino.h"

void switchKaku(int pin, unsigned long id, int group, int dev, bool state, int repeat, int dimlevel = -1);
void sendKakuCode(int pin, unsigned long code, int repeat);
void sendBit(int value, int pin, int period);
void sendSyc(int pin, int period);
void sendKakuDimCode(int pin, unsigned long id, unsigned long code, int repeat);