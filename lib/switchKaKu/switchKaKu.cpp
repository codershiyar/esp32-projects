/*  Switch Klik aan/Klik uit switches transmitter
 *  Usage: switchKaku(int pin, unsigned long id, int group, int dev, bool state, int repeat)
 *  pin = pin number
 *  id = unique id of transmitter (max 4194303)
 *  group = between 1 and 4, 
 *  device = between 1 and 4, -1 switches the entire group
 *  state = true (on) or false (off)
 *  repeat = transmit repeats
 *  dimlevel = -1 (no dimmer), between 0 and 15 for the dimlevel
 */
 #include "switchKaKu.h"
 
void switchKaku(int pin, unsigned long id, int group, int dev, bool state, int repeat, int dimlevel){
  if (dev == -1){
    dev = 1<<5;
  } else {
    dev -= 1;
  }
  if (dimlevel == -1) {
  	sendKakuCode(pin, ((id<<6|dev)|state<<4)|(group-1)<<2, repeat);
  } else {
    sendKakuDimCode(pin, id, (((dev<<4)|state<<8)|(group-1)<<6)|dimlevel, repeat);
  }
}

void sendKakuCode(int pin, unsigned long code, int repeat){
  int period = 230;
  pinMode(pin, OUTPUT);
  for (int j = 0; j < repeat; j++){
    sendSyc(pin, period);
    for (int i = 31; i>=0; i--){
      sendBit(((code & (1<<i))==(1<<i)), pin, period);
    }
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);    
    digitalWrite(pin, LOW);
  }
}

void sendKakuDimCode(int pin, unsigned long id, unsigned long code, int repeat){
  int period = 230;
  pinMode(pin, OUTPUT);
  for (int j = 0; j < repeat; j++){
    sendSyc(pin, period);  
    for (int i = 25; i>=0; i--){
      sendBit(((id & (1<<i))==(1<<i)), pin, period);
    }
    for (int i = 9; i>=0; i--){
      if (i == 8) {
      	sendBit(-1, pin, period);
      } else {
      	sendBit(((code & (1<<i))==(1<<i)), pin, period);
      }
    }
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);    
    digitalWrite(pin, LOW);
  };
}


void sendSyc(int pin, int period){
	digitalWrite(pin, LOW);
    delayMicroseconds(47*period);
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);
    digitalWrite(pin, LOW);
    delayMicroseconds(period*12);

}

void sendBit(int value, int pin, int period){
  if (value == 0){
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);
    digitalWrite(pin, LOW);
    delayMicroseconds(period*1.4);
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);
    digitalWrite(pin, LOW);
    delayMicroseconds(period*6);
  } else if (value == 1) {
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);
    digitalWrite(pin, LOW);
    delayMicroseconds(period*6);
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);
    digitalWrite(pin, LOW);
    delayMicroseconds(period*1.4);
  } else {
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);
    digitalWrite(pin, LOW);
    delayMicroseconds(period*1.4);
    digitalWrite(pin,HIGH);
    delayMicroseconds(period);
    digitalWrite(pin, LOW);
    delayMicroseconds(period*1.4);
  }
}