# RF-IR Bridge

![remote control outlets](https://i.imgur.com/qabJeXFt.jpg)

Suppose you have a set of Etekcity (or similar) remote-control outlets. You want to use some of the buttons on the remote to control devices that only respond to IR (TV/projector/etc) or WOL (computers). This project uses an Arduino Yun to listen for certain button presses on the etekcity remote, and send a power on/off command to the projector and computer.

### Dependencies

 - [rc-switch](https://github.com/sui77/rc-switch)
 - [Arduino-IRremote](https://github.com/z3t0/Arduino-IRremote)

### Hardware

 - Arduino Yun
 - 315MHz transmitter/receiver
 - IR emitter/sensor

### Configuration

 - Copy in the [code(s) sent from the remote](https://github.com/sui77/rc-switch/blob/master/examples/ReceiveDemo_Simple/ReceiveDemo_Simple.ino)
 - Copy in the [code to send to the projector](https://github.com/z3t0/Arduino-IRremote/blob/master/examples/IRrecvDumpV2/IRrecvDumpV2.ino)
 - If you are hoping to use WOL, you'll need to copy in the MAC address of the machine to wake (also make sure the computer has WOL enabled in the BIOS, it is usually off by default)
 
Note there is an unusual arrangement of loops and delays in the IR transmit code. This is to workaround some issues with my projector. You may or may not need them. 

### Construction
[![yun pinout](https://i.imgur.com/Tws6Pxdm.png)](https://i.imgur.com/Tws6Pxd.png)
 - Connect ATAD of the RF receiver to pin 18 (either one)
 - Connect Vcc of the RF receiver to 5v
 - Connect GND of the RF receiver to GND
 - Connect IR LED + to pin 32
 - Connect IR LED - to GND
 - Connect ethernet (for WOL) and power

### Alternatives

Note that you could achieve the same functionality much more easily buy buying into an existing home automation platform (SmartThings/Wink/etc) but what's the fun in that?
