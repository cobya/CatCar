/**************************************************************************************************/

/*
* File: DataSink.h
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: Defines the DataSink class used for output data and the function prototypes of the class
*
*/

/**************************************************************************************************/

using namespace std;

#ifndef DATASINK_H
#define DATASINK_H

#include<stdio.h>
#include<vector>
#include<fstream>
#include<iostream>
#include"Input.h"
#include"State.h"

/* The DataSink class is designed to store the data that has already been analyzed and is ready to be outputted. Also writes the output file. */
class DataSink {
	
	public:
		DataSink(); // Empty constructor for a DataSink class
		DataSink(char *filename) : _filename(filename) {}; // DataSink constructor which inputs a specified filename
		
		void WriteOutputs(); // Writes the output data to a specified file
		void AddOutput(State addState); // Adds a new state to the output vector
		bool IsGood(); // Checks for file validity

		vector<State> GetOutputs() const { // Returns the vector of outputs
			return _outputs;
		};

		ofstream& GetOutputFile() { // Gets the specified output file
			return this->_outputFile;
		};

		char* GetFileName() const { // Gets the DataSink's filename
			return _filename;
		};

		void PrintOutputs(); // Prints the outputs to console for debugging

	private:
		vector<Input> _inputs; // Used to store the inputs 
		ofstream _outputFile; // Output stream for the output file
		vector<State> _outputs; // Used to store the outputs
		char* _filename; // The filename of the output file
};

#endif