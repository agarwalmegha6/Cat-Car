#ifndef VEHICLE_H
#define VEHICLE_H
/*************/
/*
 * File: Vehicle.h
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This header file defines the class called Vehicle which takes in a control, updates the state and then returns it.
 */

#include "State.h"
#include "Input.h"

// Wheelbase length in meters.
#define L 2.6187

/* The State class has one private State object and 4 methods. */
class Vehicle {
    
private:
    
    State _state; // the Current state of the vehicle.
    
    void setState( State x ); // Sets the value for _state.
    
public:
    
    // Constructs a new Vehicle object with the default State value.
    Vehicle( );
    
    // Executes the Vehicle for the duration specified.
    // This method does not do any correctness checking on values in u.
    void stateUpdate( Input u, double duration );
    
    State getState( ) const; // Gets the value for _state.
};

#endif // VEHICLE_H
