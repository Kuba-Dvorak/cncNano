#include <Arduino.h>

// v commandu jsem pouzil to ze kdyz je treba G1 tak to je 1, G21 je 21, jasne?
struct basicCMD {
    uint8_t command;
    float x, y, z;
    float speed;
};


struct calibration {
    float stepTimeX, stepTimeY, stepTimeZ;
    float stepLenghtX, stepLenghtY, stepLenghtZ;
};


struct toolheadInfo {
    float x, y, z;
    uint8_t stopXfront, stopYfront, stopZfront, stopXend, stopYend, stopZend;
};


void setup() {
// write your initialization code here
}

void loop() {
// write your code here
}