#ifndef INPUT_H
#define INPUT_H

/*************/
/*
 * File: Input.h
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This file describes the interface for the Input class. It defines the two constructors and the setter and getter methods of the class.
 */

// M_PI and other variables are defined in here
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

// the MAX and MIN values for tire angle are used
// in the setTireAngle method
#define MAX_TIRE_ANGLE_RATE 0.5236
#define MIN_TIRE_ANGLE_RATE -0.5236

/* This class has three private variables and the setter and getter methods for the three variables. */
class Input{
    
private:
    
    double _velocity; // Commanded vehicle velocity (u1).
    
    double _tire_angle_rate; // Commanded tire angle rate (u2).
    
    double _timestamp; // Time stamp at which this command is valid.
    
public:
    
    // Constructs a new Input object with these initial values.
    Input(double vel, double tireAngleRate, double timestamp);
    
    // Constructs an empty Input object.
    Input();

    double getVelocity() const; // Returns the _velocity.
    
    void setVelocity(double vel); // Sets the _velocity.
    
    double getTireAngleRate() const; // Returns the _tire_angle_rate.
    
    void setTireAngleRate(double angle); // Sets the _tire_angle_rate.
    
    double getTimeStamp() const; // Gets the _timestamp.
    
    void setTimeStamp(double timestamp); // Sets the _timestamp.
};

#endif // INPUT_H
