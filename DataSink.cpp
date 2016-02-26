/**************************************************************************************************/

/*
 * File: DataSource.cpp
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: DataSink class which implements the state generation and output file writing functionality.
 *
 */

/**************************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

//Includes all the header files for clarity.
#include "Input.h"
#include "State.h"
#include "Vehicle.h"
#include "DataSource.h"
#include "Director.h"
#include "DataSink.h"

/**************************************************************************************************/

// Default Constructor.
DataSink::DataSink() {
    
}

// Method to add State to the vector of state objects.
void DataSink::addState(State s)
{
    stateData.push_back(s); // Uses vector.push_back method to insert the object.
}

// Method to return the state.
vector<State> DataSink::getState()
{
    return stateData; // Returns the vector of state objects.
}

//Method to generate the state by using Vehicle class.
void DataSink::generateState(vector<Input> input) {
    
    double duration = 0.0; // Temporary variable for storing duration.
    
    for(int j = 0;j<input.size();j++) // Loop to calculate duration and then update the state accordingly.
    {
        
        if(j == input.size() -1)
        {
            duration = 0.2; // Duration is set 0.2 for the last one.
        }
        
        else
        {
        duration = input.at(j+1).getTimeStamp()-input.at(j).getTimeStamp(); // Duration is calculated.
        }
        
        stateGenerator.stateUpdate(input.at(j),duration); // Method to update the state of the current object using the Vehicle class.
        
        addState(stateGenerator.getState()); // Adds the updated state to the vector of state objects.
        
    }
}
bool DataSink::WriteOutputFile(string outfile, bool res) {
    
    ofstream outFS; // Output file stream.
    
    // Open file.
    outFS.open(outfile.c_str());
    
    if (!outFS.is_open()) {
        
        // Prints out the error statement accordingly.
        std::cerr << "Error! Unable to write to file " << outfile << ". Aborting." << std::endl;
        return false;
        
    }
    if(res) // Checks if validation results in true.
    {
    for(int k =0;k<stateData.size();k++)
    {
        // Writes to output file as a csv file.
        outFS<<stateData.at(k).getTimeStamp()<<','<<stateData.at(k).getXPos()<<','<<stateData.at(k).getYPos()<<','<<stateData.at(k).getTireAngle()<<','<<stateData.at(k).getHeading()<<endl;
    }
    }
    
    outFS.close(); // Closes the output stream.
    
    return true;
}

/**************************************************************************************************/
