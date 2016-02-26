/**************************************************************************************************/

/*
 * File: DataSource.cpp
 * Author: Megha Agarwal
 * NetID: meghaagarwal
 * Date: October 30, 2015
 *
 * Description: This cpp file contains the implementation for performing the reading from file, sorting and validating operations on the control inputs.
 *
 */

/**************************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include<fstream>
#include<vector>

// Includes all the header files for clarity.

#include "Input.h"
#include "State.h"
#include "Vehicle.h"
#include "DataSource.h"
#include "Director.h"
#include "DataSink.h"

/**************************************************************************************************/

// Default constructor.
DataSource::DataSource() {
    
    // Initializes the temporary variables to 0.0.
    this->velocity = 0.0;
    this->tireAngleRate = 0.0;
    this->timeStamp = 0.0;
}

// Method to read from input file and check for errors.
bool DataSource::ReadInputFile( std::string filename)
{
    
    bool result = false;
    
    ifstream file; // Input file stream.
    
    file.open(filename.c_str( )); // Open file.
    
    if (!file.is_open())
    {
        // Prints error message accordingly.
        std::cerr << "Error! Unable to read from file " << filename << ". Aborting." << std::endl;
        
        result = false;
        return result;
    }
    
    // Reads data from file.
    while (!file.eof()) {
        
        // Stores data in temporary variables.
        file>>velocity;
        file>>tireAngleRate;
        file>>timeStamp;
        
    if(!file.fail())
    {
        // Pushes data to the vector of input objects.
        inputData.push_back(Input(velocity,tireAngleRate,timeStamp));
    }
    }
    file.close(); // Closes the file.
    return true;
    
}

// Method to complete the partition part of the quicksort algorithm.
int DataSource::partition(int i, int k) {
    
        int l = 0; // Lower point.
        int h = 0; // Higher point.
    
        int midpoint = 0;
        double pivot = 0.0; // Pivot point.
    
        double temp = 0.0; // Temporary variable for swapping.
    
        bool done = false;
        
        /* Pick middle element as pivot */
    
        midpoint = i + (k - i) / 2; // Middle point.
        pivot = inputData.at(midpoint).getTimeStamp(); // Pivot according to timeStamp.
        
        l = i;
        h = k;
        
        while (!done) {
            
            /* Increment l while timeStamp < pivot */
            while (inputData.at(l).getTimeStamp() < pivot) {
                ++l;
            }
            
            /* Decrement h while pivot < timeStamp */
            while (pivot < inputData.at(h).getTimeStamp()) {
                --h;
            }
            
            /* If there are zero or one elements remaining,
             all numbers are partitioned. Return h */
            if (l >= h) {
                done = true;
            }
            else {
                /* Swap timeStamp of l and timeStamp of h,
                 update l and h */
                temp = inputData.at(l).getTimeStamp();
                inputData.at(l).setTimeStamp(inputData.at(h).getTimeStamp());
                inputData.at(h).setTimeStamp(temp);
                
                ++l;
                --h;
            }
        }
        
        return h;
    }

// Method to complete part of the quicksort algorithm.
void DataSource::sort(int i, int k) {
    
        int j = 0; // Counter for partition.
        
        /* Base case: If there are 1 or zero elements to sort,
         partition is already sorted */
        if (i >= k) {
            return;
        }
        
        /* Partition the data within the array. Value j returned
         from partitioning is location of last element in low partition. */
        j = partition(i, k);
        
        /* Recursively sort low partition (i to j) and
         high partition (j + 1 to k) */
        sort(i, j);
        sort(j + 1, k);
        return;
    }

// Method to validate the control inputs.
bool DataSource::validate() {
        
        double dur = 0.0; // Duration variable.
        
        for(int a = 0;a<inputData.size();a++)
        {
            if(a == inputData.size() -1)
            {
                dur = 0.2; // Calculates duration.
            }
            else
            {
                dur = inputData.at(a+1).getTimeStamp()-inputData.at(a).getTimeStamp();
            }
            
            // Checks for timeStamp of 0.
            if(inputData.at(0).getTimeStamp()!=0.0)
                return false;
            // Checks for range of TireAngle.
            if(inputData.at(a).getTireAngleRate()< MIN_TIRE_ANGLE || inputData.at(a).getTireAngleRate()>MAX_TIRE_ANGLE)
                return false;
            // Checks for velocity range.
            if(inputData.at(a).getVelocity()<0.0 || inputData.at(a).getVelocity()>30.0)
                return false;
            // Checks for non-negative timeStamps.
            if(inputData.at(a).getTimeStamp()<0)
                return false;
            // Checks for duration range.
            if(dur<0.005 || dur>0.201)
                return false;
        }
        return true;
            }

// Method to return the vector of input objects.
vector<Input> DataSource::getInput() {
    
    return inputData;
}
/**************************************************************************************************/
