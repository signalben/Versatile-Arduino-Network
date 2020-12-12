//Network Definitions
#include "netDef.h"

  //Get via Serial.println(WiFi.macAddress());
  //This ESP is static (new): MAC{0x10, 0x52, 0x1C, 0x68, 0xF3, 0xB0}; 
  //Other ESP is buggy (old): {0xFC, 0xF5, 0xC4, 0x0F, 0xBE, 0xFC};

uint8_t peerMAC[] = {0xFC, 0xF5, 0xC4, 0x0F, 0xBE, 0xFC}; //Adress of other esp
esp_now_peer_info_t peerInfo;

bool verboseLog = false;
bool errorLog = false;
int vanSerial;

const uint8_t  
START = '\a',
END = '\0';

//Device addresses, must be constant for all nodes:
const uint8_t
ULTRASOUND = 16,
PC = 3,
NANO = 4,
MEGA = 1,
ESP32BUGGY = 2,
ESP32STATIC = 5;

const uint8_t THISNODE = 5;//esp connected via serial to PC
//address 0x00 not allowed

//The following defines all objects in the newtork, relative to this nodes location:

//Devices local to this node (this node, sensors, actuators, functions)
const uint8_t LOCALDEVICE[1] = {THISNODE};

//All other device ID's connected via serial port 0
const uint8_t SPORT0[1] = {PC};
const uint8_t SPORT1[0] = {};
const uint8_t SPORT2[0] = {};
const uint8_t SPORT3[5] = {ESP32BUGGY, MEGA, NANO, ULTRASOUND};

////Counts of local devices, and devices reachable on each port
const uint8_t 
N_LOCALDEVICE = 1,
N_SPORT0 = 1,
N_SPORT1 = 0,
N_SPORT2 = 0,
N_SPORT3 = 4;

//this node's network map is now defined

//Standard message CMD codes
const uint8_t
REPORT = 1,
PERIOD = 2,
ECHO = 3,
RESPONSE = 4,
SETDEST = 5,
REPORTNOW = 6;
