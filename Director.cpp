/**************************************************************************************************/

/*
 * File: Director.cpp
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: Director class for the implementation of interaction between DataSource and DataSink.
 *
 */

/**************************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

// Includes all the header files for clarity.
#include "Input.h"
#include "State.h"
#include "Vehicle.h"
#include "DataSource.h"
#include "Director.h"
#include "DataSink.h"

/**************************************************************************************************/

// Default constructor.
Director::Director() {
    
}

// Constructor which calls the methods of DataSource and DataSink class.
Director::Director(string inputfile, string outputfile)
{
    // Method call for read input.
    if(!source.ReadInputFile(inputfile))
    {
        return;
    }
    // Method call for sort.
    source.sort(0,source.getInput().size()-1);
    // Method call for generateState which updates the State.
    sink.generateState(source.getInput());
    // Method call for write in output file.
    if(!sink.WriteOutputFile(outputfile,source.validate()))
    {
        return;
    }
}

/**************************************************************************************************/
