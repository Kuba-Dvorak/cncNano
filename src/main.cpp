#include <Arduino.h>
#include <Wire.h>
#include <array>


// v commandu jsem pouzil to ze kdyz je treba G1 tak to je 1, G21 je 21, jasne?a


struct position {
    float x, y;
};


struct basicCMD {
    uint8_t command;
    position position;
    float z;
};


struct calibration {
    float stepTimeX, stepTimeY, stepTimeZ;
    float stepLenghtX, stepLenghtY, stepLenghtZ;
};


struct toolheadInfo {
    position position;
    float z;
    bool stopXfront, stopYfront, stopZfront, stopXend, stopYend, stopZend;
};


calibration basicCalib() {
    calibration calib;
    calib.stepTimeX = 0.001;
    calib.stepTimeY = 0.001;
    calib.stepTimeZ = 0.001;

    calib.stepLenghtX = 0.01;
    calib.stepLenghtY = 0.01;
    calib.stepLenghtZ = 0.01;

    return calib;
}


toolheadInfo basicToolHead() {
    toolheadInfo toolHead;
    toolHead.position.x = 0;
    toolHead.position.y = 0;
    toolHead.z = 0;

    toolHead.stopXfront = false;
    toolHead.stopYfront = false;
    toolHead.stopZfront = false;

    toolHead.stopXend = false;
    toolHead.stopYend = false;
    toolHead.stopZend = false;

    return toolHead;
}


struct cnc {
    calibration myCalib;
    toolheadInfo myToolHead;
    std::array<int, 9> motorPins; // X step, X dir, X ena, Y .... Z ...
    std::array<int, 6> endStop;

    cnc(std::array<int, 9> motorPins, std::array<int, 6> endStop) {
        this->motorPins = motorPins;
        this->endStop = endStop;
        myCalib = basicCalib();
        myToolHead = basicToolHead();
    }

    void operateInstr(basicCMD curCMD) {

    }

    void move2D(position location) {
        if (location.x >= myToolHead.position.x) {
            digitalWrite(motorPins[1], HIGH);
        }

        else {
            digitalWrite(motorPins[1], LOW);
        }

        if (location.y >= myToolHead.position.y) {
            digitalWrite(motorPins[4], HIGH);
        }

        else {
            digitalWrite(motorPins[4], LOW);
        }


    }

    void oneStep() {
        digitalWrite(motorPins[0], HIGH);
        delayMicroseconds(1000);
        digitalWrite(motorPins[0], LOW);
        digitalWrite(motorPins[1], HIGH);
        delayMicroseconds(1000);
        digitalWrite(motorPins[1], LOW);
    }
};


void setup() {
    // write your initialization code here
}

void loop() {
    // write your code here
}