/**************************************************************************************************/

/*
 * File: Vehicle.cpp
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This is a class which takes in a control, updates the state and then returns it.
 *
 */

/**************************************************************************************************/

// Includes header files for clarity.
#include <iostream>
#include <math.h>
#include "Vehicle.h"

// Constructs a new Vehicle object with the default State value.
Vehicle:: Vehicle() {
    
    _state.setXPos(0.0);
    _state.setYPos(0.0);
    _state.setTireAngle(0.0);
    _state.setHeading(0.0);
    
}

// Sets the value for _state.
void Vehicle::setState(State x)
{
    _state = x;
    return;
}

// Executes the Vehicle for the duration specified.
// This method does not do any correctness checking on values in u.
void Vehicle::stateUpdate(Input u, double duration)
{
    // Temporary variables.
    double _x1;
    double _x2;
    double _x3;
    double _x4;
    
    _x1 = _state.getXPos()+duration*u.getVelocity()*cos(_state.getTireAngle())*cos(_state.getHeading());
    
    _x2 = _state.getYPos()+duration*u.getVelocity()*cos(_state.getTireAngle())*sin(_state.getHeading());
    
    _x4 = _state.getHeading()+duration*u.getVelocity()*(1/L)*sin(_state.getTireAngle());
    
    //Saturation check.
    if(_x4<0)
        _x4 = _x4 + M_TWO_TIMES_PI;
    if(_x4>=M_TWO_TIMES_PI)
        _x4 = _x4 - M_TWO_TIMES_PI;
    
    _x3 = _state.getTireAngle()+duration*u.getTireAngleRate();
    
    //Saturation check.
    if(_x3<MIN_TIRE_ANGLE)
        _x3 = MIN_TIRE_ANGLE;
    if(_x3>MAX_TIRE_ANGLE)
        _x3 = MAX_TIRE_ANGLE;
    
    // State update.
    _state.setXPos(_x1);
    _state.setYPos(_x2);
    _state.setTireAngle(_x3);
    _state.setHeading(_x4);
    _state.setTimeStamp(u.getTimeStamp()+duration);
}

// Gets the value for _state.
State Vehicle::getState() const{
    return _state;
}

