
#include "netDef.h"
#include<vanUno.h>
#include<node.h>
#include<van_dev_ultrasound.h>

van_us US0(ULTRASOUND, 11, 12);

void commandList(Message inData) {
  if (inData.dest == THISNODE) {
    CMD_VAN_NODE(inData);
  }
  if (inData.dest == ULTRASOUND) {
    US0.command(inData);
  }
}

void reportList() {
  US0.autoReport();
}

void setup() {
  Serial.begin(115200);
  US0.period = 100;
  US0.destination = PC;
}

void loop() {
  handleMessage(getMessage(0));
  reportList();
}
