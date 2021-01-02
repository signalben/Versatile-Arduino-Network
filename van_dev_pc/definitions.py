#Third party modules:
import serial
import time
import threading
import tkinter as tk # Python 3.x Version
import matplotlib.pyplot as plt
import numpy as np

STD = 7
ACK = 90
RESP = 110

name2Address = {
"MEGA" : 1,
"ESP32BUGGY" : 2,
"PC" : 3,
"NANO" : 4,
"ESP32STATIC" : 5,
"ULTRASOUND" : 16,
"JOYSTICK" : 17,
"MOTORS" : 20,
"SKIDSTEER" : 30,
"PID" : 31,
"IMU" : 18,
"REMOTE" : 19,
"NANO_ENC" : 6
}

address2Name = {v:k for k, v in name2Address.items()}

name2Command = {
"REPORT" : 1,
"PERIOD" : 2, 
"ECHO"   : 3,
"RESPONSE" : 4,
"SETDEST" : 5, 
"REPORTNOW" : 6,
"SET": 7,
"P0" : 8,
"P1" : 9,
"P2" : 10,
"P3" : 11
}

command2Name = {v:k for k, v in name2Command.items()}



