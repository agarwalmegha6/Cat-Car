#ifndef DATASINK_H
#define DATASINK_H
/*************/
/*
 * File: DataSink.h
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This header file defines the class called DataSink which implements the operations of generating the outputs by updating state and then writing them into the output file. */

// Includes header files for clarity.
#include <stdio.h>
#include"Input.h"
#include "State.h"
#include "Vehicle.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/* This class has two private variables of type vector<State> and Vehicle and five methods to implement the state generation and writing data to output file operations. */
class DataSink {
    
private:
    
    vector<State> stateData; // A vector of objects of type State.
    
    Vehicle stateGenerator; // An object of type Vehicle.
    
public:
    
    DataSink(); // A default constructor.
    
    void addState(State s); // Method to add State to the vector of state objects.
    
    vector<State> getState(); // Method to return the state.
    
    void generateState(vector<Input> input); //Method to generate the state by using Vehicle class.
    
    bool WriteOutputFile(string outfile, bool res); // Method to write data to output file.
};

#endif // DATASINK_H
