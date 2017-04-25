/**************************************************************************************************/

/*
 * File: main.cpp
 * Author: Coby Allred
 * NetID: cobyallred
 * Date: 10/27/16
 *
 * Description: main.cpp will execute the catcar program by calling the various dataclasses and the 
 *
 */

/**************************************************************************************************/


using namespace std;

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

// Including the header files which define the classes and functions used in the program
#include "Input.h"
#include "State.h"
#include "Vehicle.h"
#include "DataSource.h"
#include "DataSink.h"
#include "Director.h"

/**************************************************************************************************/


int main(int argc, char *argv[]) {

	if (argc != 3) { // If the user has not entered the correct number of arguments, print usage statement
		cout << "Usage: catcar controlInputs stateOutputs" << endl;
		return EXIT_FAILURE;
	}

	DataSource source(argv[1]); // Construct DataSource from specified inputs file
	DataSink sink(argv[2]); // Construct the DataSink

	if (source.IsGood()) { // If input file is valid, read inputs
		source.ReadInputs(); // Read the inputs from the source file
	}
	else { // If not valid, return EXIT_FAILURE
		cout << "Error opening " << argv[1] << "for reading." << endl;
		return EXIT_FAILURE;
	}
	
	Director director(&source, &sink); // Creates the director class using the previous source and sink
	director.Execute(); // Executes the sort and main calculations on the input file

	if (sink.IsGood()) { // If the output file is valid, write output file
		sink.WriteOutputs(); // Printing the output states to specified file
	}
	else { // If not valid, return EXIT_FAILURE
		cout << "Error opening " << argv[2] << "for writing." << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

/**************************************************************************************************/
