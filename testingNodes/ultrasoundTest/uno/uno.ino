#include "netDef.h"
#include<vanUno.h>
#include<node.h>
#include<van_dev_ultrasound.h>

ackbuff AKB0;//Create a buffer to store messages to be repeatedly sent until an acknowledgement is recieved 
van_us US0(ULTRASOUND, 11, 12);

void commandList(Message inData) {
  if (inData.dest == THISNODE) {
    //CMD_VAN_NODE(inData);
    //showMessage(inData);
    Serial.println(inData.getDataInt());
  }
  if (inData.dest == ULTRASOUND) {
    US0.command(inData);
  }
}

void reportList() {
  AKB0.handleWaiting();
  US0.autoReport(); 
}

void setup() {
  Serial.begin(115200);
  //Serial.print("OK");
  US0.period = 1000;
  US0.destination = THISNODE;
  AKB0.period = 100;
}

void loop() {
  handleMessage(getMessage(0));
  reportList();
}
