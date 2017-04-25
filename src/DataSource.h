/**************************************************************************************************/

/*
* File: DataSource.h
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: This file implements the function prototypes defined in DataSource.h which handle the operations used in the DataSource class
*
*/

/**************************************************************************************************/

using namespace std;

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include<stdio.h>
#include<vector>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include"Input.h"

/* The DataSource class contains all of the input data and the functions to read data from a specified file */
class DataSource{
	
	public:
		DataSource(); // Default Constructor
		DataSource(char *filename) : _filename(filename) {}; // Constructor for specified filename
		
		void ReadInputs(); // Reading the inputs from specified file
		bool IsValidInput(Input in); // Checks for valid input data
		bool IsGood(); // Checks whether or not DataSource file is good

		// 
		char* GetFileName() const { // Returns the input filename
			return this->_filename; 
		};

		//
		ifstream& GetInputFile() { // Returns the input filestream
			return this->_inputFile;
		};

		//
		vector<Input> GetInputs() const { // Returns the vector of stored inputs
			return _inputs;
		};

		void sort(int left, int right); // Sorts the input vectors using Quick Sort
		
		bool AreInputsValid(); // Searches through list to find any invalid inputs
		void PrintInputs(); // Prints the entire list of Inputs

	private:
		vector<Input> _inputs; // Vector to store data
		char *_filename; // Filename
		ifstream _inputFile; // Input filestream

		int sortPartition(int left, int right); // Partitions the data for Quick Sort
};



#endif