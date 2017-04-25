/**************************************************************************************************/

/*
* File: DataSource.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: Implements the DataSource funtions to read the data from a file and check whether or not it is valid
*
*/

/**************************************************************************************************/

using namespace std;

#include"DataSource.h"
#include <string>

DataSource::DataSource() {
	// Do nothing, empty constructor
	return;
}

// ReadInputs will read the input data from a given file
void DataSource::ReadInputs() {
	if (_filename != NULL) {
		Input readInput;
		double time, tireAngleRate, velocity;
		string inputLine;

		_inputFile.open(_filename); // Opening the inputs file

		if (_inputFile.is_open()) { // If able to open the input file
			while (getline(_inputFile, inputLine)) {  // Gets a line from the input file and repeats until end of file
				
				istringstream inputLineStream(inputLine); // Used to analyze the inputted line
				inputLineStream >> time; // Getting input timestamp
				inputLineStream >> velocity; // Getting input velocity
				inputLineStream >> tireAngleRate; // Getting input tireAngleRate

				// Setting the temporary input values to the read values
				readInput.setTimeStamp(time);
				readInput.setTireAngleRate(tireAngleRate);
				readInput.setVelocity(velocity);

				if (IsValidInput(readInput)) { // If the input data is all valid, add it to the list of inputs
					_inputs.push_back(readInput);
				}
				else { // If not valid, force set to -1 to trip whole input valid check and add
					readInput.setTimeStamp(-1);
					readInput.setTireAngleRate(-1);
					readInput.setVelocity(-1);
					_inputs.push_back(readInput);
				}
			}
		}
		else { // If there is an error opening the file, print error opening
			cout << "Error opening " << _filename << endl;
		}

		_inputFile.close(); // Closing the inputs file

		if (_inputs.size() != 0) { // If there were inputs
			sort(0, _inputs.size()); // Sorts the inputs based on timestamp using quicksort
		}

	}

	return;
}

// The recursive sorting algorithm Quick Sort
void DataSource::sort(int p, int q) {
	int partition;

	if (p < q) { 
		partition = sortPartition(p, q); // Creating the partitions
		sort(p, partition); // Recursive sorting based off of the partition 
		sort(partition + 1, q); // Recursive sorting based off of the partition 
	}

	return;
}

// Making the partitions used in the Quick Sort algorithm
int DataSource::sortPartition(int p, int q) {
	int i = p;
	int j;

	for (j = p + 1; j < q; j++) { // Finds where to partition the data
		if (_inputs.at(j).getTimeStamp() <= _inputs.at(p).getTimeStamp()) {
			i = i + 1;
			swap(_inputs.at(i), _inputs.at(j)); // Swap values
		}
	}

	swap(_inputs.at(i), _inputs.at(p)); // Swap values
	return i;
}

// Makes sure the input is a valid input
bool DataSource::IsValidInput(Input in) {
	if (in.getTireAngleRate() == -1 || in.getVelocity() == -1 || in.getTimeStamp() < 0) { // If validity checks fail, return false
		return false;
	}
	return true; // Else return true
}

// Check to see if entire set of inputs is valid
bool DataSource::AreInputsValid() {
	if (_inputs.size() == 0) {
		return false;
	}
	
	int i = 0;
	for (i = 0; (unsigned)i < this->_inputs.size() -1; i++) {  // Increments through vector of inputs to check for valid data
		if ((this->_inputs.at(i + 1).getTimeStamp() - this->_inputs.at(i).getTimeStamp()) > .201) {
			return false;
		}
	}
	return true;
}

// Checks to see if input file is valid
bool DataSource::IsGood() {
	return	_inputFile.good();
}

// Prints set of inputs which is used in debugging
void DataSource::PrintInputs() {
	int count = 0;
	
	cout << "Inputs" << endl;

	for (count = 0; (unsigned)count < this->_inputs.size(); count++) {
		cout << this->_inputs.at(count).getTimeStamp() << ", " << this->_inputs.at(count).getVelocity() << ", " << this->_inputs.at(count).getTireAngleRate() << endl;
	}

	return;
}
