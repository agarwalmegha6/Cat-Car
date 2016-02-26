/**************************************************************************************************/

/*
 * File: State.cpp
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This is a class which holds the output values for the state of the car.
 *
 */

/**************************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

// Includes header files for clarity.
#include "Input.h"
#include "State.h"
#include "Vehicle.h"



/**************************************************************************************************/

// Constructs a new State object with these initial values
State::State(double x1, double x2, double x3, double x4, double timestamp) {
    setXPos(x1);
    setYPos(x2);
    setTireAngle(x3);
    setHeading(x4);
    setTimeStamp(timestamp);
    return;
}

// Constructs an empty State object
State::State() {
    setXPos(0.0);
    setYPos(0.0);
    setTireAngle(0.0);
    setHeading(0.0);
    setTimeStamp(0.0);
    return;
}

// Returns the _xpos.
double State::getXPos() const {
    return _xpos;
}

// Sets the _xpos.
void State::setXPos(double xpos) {
    _xpos = xpos;
}

// Returns the _ypos.
double State::getYPos() const {
    return _ypos;
}

// Sets the _ypos.
void State::setYPos(double ypos) {
    _ypos = ypos;
}

// Returns the _tire_angle.
double State::getTireAngle() const {
    return _tire_angle;
}

// Sets the _tire_angle.
void State::setTireAngle(double angle) {
    _tire_angle = angle;
}

// Gets the _heading.
double State::getHeading() const {
    return _heading;
}

// Sets the _heading.
void State::setHeading(double heading) {
    _heading = heading;
    }

// Gets the _timestamp.
double State::getTimeStamp() const {
    return _timestamp;
}

// Sets the _timestamp.
void State::setTimeStamp(double timestamp) {
    _timestamp = timestamp;
}

/**************************************************************************************************/
