#include <RCSwitch.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <Process.h>

RCSwitch mySwitch = RCSwitch();
IRsend irsend;

void setup() {
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0
  Bridge.begin();
}

void loop() {
  if (mySwitch.available()) {
    long rfCode = mySwitch.getReceivedValue();
    if (rfCode == 89347 || rfCode == 95491) { //turn on
      for (int i = 0; i<5; i++) {
        irsend.sendNEC(0x4CB340BF, 32);
        delay(40);
      }
      sendWOL();
    } else if (rfCode == 89356 || rfCode == 95500) { //turn off
      for (int i = 0; i<3; i++) {
        irsend.sendNEC(0x4CB3748B, 32);
        delay(400);
      }
    }
    mySwitch.resetAvailable();
  }
}

void sendWOL() {
  Process p;
  p.begin("wol");
  p.addParameter("D0:50:99:52:BC:14");
  p.run();
}

