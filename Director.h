#ifndef DIRECTOR_H
#define DIRECTOR_H
/*************/
/*
 * File: Director.h
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This header file defines the director class which passes the control inputs to the Vehicle for updating the values.
 */

//Includes all header files for clarity.
#include<string>
#include "Input.h"
#include "State.h"
#include "Vehicle.h"
#include "DataSource.h"
#include "Director.h"
#include "DataSink.h"

using namespace std;

/* This class has two private objects of type DataSource and DataSink and two constructors for interatcion.*/
class Director{
    
private:
    
    DataSource source; // An object of DataSource class.
    
    DataSink sink; // An object of DataSink class.
    
public:
    
    Director(); // Default constructor.
    
    Director(string inputfile, string outputfile); // Constructor which calls the methods of DataSource and DataSink class.
};


#endif // DIRECTOR_H
