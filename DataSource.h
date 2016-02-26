#ifndef DATASOURCE_H
#define DATASOURCE_H
/*************/
/*
 * File: DataSource.h
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This header file defines the class called DataSource which performs the reading from file, sorting and validating operations on the control inputs.
 */

// Includes header files for clarity.
#include <stdio.h>
#include"Input.h"
#include "State.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/* This class consists of four private variables and six methods which perform read, sort and validate functions. */
class DataSource{
    
private:
    
    vector<Input> inputData; // A vector of objects of type Input.
    
    double velocity; // Commanded vehicle velocity (u1) (Temporary).
    
    double tireAngleRate; // Commanded tire angle rate (u2) (Temporary).
    
    double timeStamp; // Time stamp at which this command is valid. (Temporary).
    
public:
    
    DataSource(); // Default constructor for DataSource.
    
    bool ReadInputFile(std::string filename); // Method to read in input file and check for failure in reading the file.
    
    vector<Input> getInput(); // Method which returns the vector of input objects.
    
    void sort(int i, int k); // Method which performs a part of the quicksort algorithm.
    
    int partition(int i, int k); // Method which performs the partition part of the quicksort algorithm.
    
    bool validate(); // Validates the control inputs from the file after they are read and sorted.
};

#endif // DATASOURCE_H
