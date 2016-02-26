/**************************************************************************************************/

/*
 * File: Input.cpp
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This class defines the two constructors and the setter and getter methods of the class
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

// Default constructor
Input::Input() {
    
    setVelocity(0.0);
    setTireAngleRate(0.0);
    setTimeStamp(0.0);
    
    return;
}

// Constructs a new Input object with these initial values.
Input::Input(double vel, double tireAngleRate, double timestamp) {
    
    setVelocity(vel);
    setTireAngleRate(tireAngleRate);
    setTimeStamp(timestamp);
    
    return;
}

// Returns the _velocity.
double Input::getVelocity() const {
    return this->_velocity;
}

// Sets the _velocity.
void Input::setVelocity(double vel)  {
    this->_velocity = vel;
}

// Returns the _tire_angle_rate.
double Input::getTireAngleRate() const {
    return this->_tire_angle_rate;
}

// Sets the _tire_angle_rate.
void Input::setTireAngleRate(double angle) {
    this->_tire_angle_rate = angle;
}

// Gets the _timestamp.
double Input::getTimeStamp() const {
    return this->_timestamp;
}

// Sets the _timestamp.
void Input::setTimeStamp(double timestamp) {
    this->_timestamp = timestamp;
}

/**************************************************************************************************/
