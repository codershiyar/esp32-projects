# switchKaKu
Arduino library for switching with the new KaKu (Klik aan Klik uit) protocol

Usage: switchKaku(int pin, unsigned long id, int group, int dev, bool state, int repeat, int dimlevel)
- pin = pin number
- id = unique id of transmitter (between 1 and 67108863)
- group = between 1 and 4, 
- device = between 1 and 4, -1 switches the entire group
- state = true (on) or false (off)
- repeat = transmit repeats
- dimlevel = -1 (no dimmer), between 0 and 15 for the dimlevel
