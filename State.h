#ifndef STATE_H
#define STATE_H

/*************/
/*
 * File: State.h
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This header file is an interface for the class State which holds the output values for the state of the car.
 */

// M_PI and other variables are defined in here
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

// the MAX and MIN values for tire angle are used
// in the setTireAngle method
#define MAX_TIRE_ANGLE 0.5236
#define MIN_TIRE_ANGLE -0.5236

// 2PI is important for values of heading
#define M_TWO_TIMES_PI (2*M_PI)

/* This class has five private variables and the getter and setter methods for them. */
class State{
    
private:
    
    double _xpos; // Vehicle position, forward (x1).
    
    double _ypos; // Vehicle position, left/right (x2).
    
    double _tire_angle; // Tire angle (radians) (x3).
    
    double _heading; // Heading (radians) (x4).
    
    double _timestamp; // Time stamp at which this state is measured.

public:
    
    // Constructs a new State object with these initial values.
    State(double x1, double x2, double x3, double x4, double timestamp);
    
    // Constructs an empty State object.
    State();

    double getXPos() const; // Returns the _xpos.
    
    void setXPos(double xpos); // Sets the _xpos.
    
    double getYPos() const; // Returns the _ypos.
    
    void setYPos(double ypos); // Sets the _ypos.
    
    double getTireAngle() const; // Returns the _tire_angle.
    
    void setTireAngle(double angle); // Sets the _tire_angle.
    
    double getHeading() const; // Gets the _heading.
    
    void setHeading(double heading); // Sets the _heading.
    
    double getTimeStamp() const; // Gets the _timestamp.
    
    void setTimeStamp(double timestamp); // Sets the _timestamp.
};

#endif // STATE_H
