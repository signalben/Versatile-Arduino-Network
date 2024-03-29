
#ifndef van_dev_pid_h
#define van_dev_pid_h
#include "Arduino.h"
#include "message.h"
#include "ackbuff.h"

extern const uint8_t
PERIOD,
REPORT,
RESPONSE,
SETDEST,
STD,
SET,
IMU,
MEGA,
PARAM0,
PARAM1,
PARAM2,
PARAM3;

extern ackbuff AKB0;
//External functions from VAN
extern void Elog(uint8_t fileNo, uint8_t errorcode);
extern void handleMessage(message inData);
extern void showMessage(message inData);

class van_pid {
private:


public:
    uint8_t thisDevice;
    uint8_t destination;
    unsigned long lastReport;
    unsigned int period;
    int rTrigPin, rDirPin, lTrigPin, lDirPin;

    van_pid(uint8_t deviceAdress, int a, int b, int c, int d);
    void command(message inData);
    void autoReport();
    void instantReport();
    void isrLeft();
    void isrRight();
};
typedef class van_pid Van_pid;

#endif