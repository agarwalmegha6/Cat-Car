/**************************************************************************************************/

/*
 * File: main.cpp
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: main method for the implementation of usage and director constructor.
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


int
main(int argc, char *argv[])
{
    int result=EXIT_SUCCESS;
    
    /* Logic to check arguments */
    if (argc != 3)
    {
        // Prints Usage statement.
        std::cout << std::endl << "Usage: " << argv[0] << " controlInputs stateOutputs"
        << std::endl << std::endl;
        result = EXIT_FAILURE;
        return result;
    }
    
    // Constructor call for director.
    Director dir(argv[1],argv[2]);

    return EXIT_SUCCESS;
}

/**************************************************************************************************/
