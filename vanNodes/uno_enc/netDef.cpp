//Network Definitions
#include "netDef.h"

const uint8_t  
START = '\a',
END = '\0';

bool verboseLog = false;
bool errorLog = false;
int vanSerial;

//Device addresses, must be constant for all nodes:
const uint8_t
ULTRASOUND = 16,
JOYSTICK = 17,
IMU = 18,
REMOTE = 19,
MOTORS = 20,
SKIDSTEER = 30,
PID = 31,
SPLITTER = 32,
ROLLOVER = 33,
IMUPID = 34,
PC = 3,
NANO = 4,
NANO_ENC = 6,
MEGA = 1,
ESP32BUGGY = 2,
ESP32STATIC = 5;

const uint8_t THISNODE = 6;//nano enc
//address 0x00 not allowed

//The following defines all objects in the newtork, relative to this nodes location:

//Devices local to this node (this node, sensors, actuators, functions)
const uint8_t LOCALDEVICE[2] = { THISNODE, PID};

//All other device ID's connected via serial port 0
const uint8_t SPORT0[13] = {PC, MEGA, NANO, ULTRASOUND, MOTORS, ESP32BUGGY, IMU, SPLITTER, IMUPID, ROLLOVER, ESP32STATIC, JOYSTICK, SKIDSTEER};

////Counts of local devices, and devices reachable on each port
const uint8_t 
N_LOCALDEVICE = 2,
N_SPORT0 = 13;

//this node's network map is now defined

//Standard message CMD codes
const uint8_t
REPORT = 1,
PERIOD = 2,
ECHO = 3,
RESPONSE = 4,
SETDEST = 5,
REPORTNOW = 6,
SET = 7,
PARAM0 = 8,
PARAM1 = 9,
PARAM2 = 10,
PARAM3 = 11,
PARAM4 = 12,
PARAM5 = 13;
