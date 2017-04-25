/**************************************************************************************************/

/*
* File: DataSink.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: This file implements the function prototypes defined in DataSink.h which handle the operations used in the DataSink class
*
*/

/**************************************************************************************************/

using namespace std;

#include"DataSink.h"

DataSink::DataSink() {
	// Do nothing, empty constructor
	return;
}

// Returns whether or not output file is valid
bool DataSink::IsGood() {
	return _outputFile.good();
}

// Write outputs to specified file
void DataSink::WriteOutputs() {

	if (this->_outputs.size() == 0) { // If there are no outputs, create and close the file
		ofstream outFile(GetFileName());
		outFile.close();
		return;
	}

	ofstream outFile(GetFileName()); // Create the output file stream

	int count = 0;
	while ((unsigned)count < _outputs.size()) { // Iterates through the list and writes the data found at the current position
		outFile << _outputs.at(count).getTimeStamp() << "," << _outputs.at(count).getXPos() << "," << _outputs.at(count).getYPos() << "," << _outputs.at(count).getTireAngle() << "," << _outputs.at(count).getHeading() << endl;
		count++;
	}

	outFile.close();

	return;
}

// Print outputs to console for debugging
void DataSink::PrintOutputs() {
	int count = 0;

	cout << "Outputs" << endl;

	for (count = 0; (unsigned)count < this->_outputs.size(); count++) {
		cout << this->_outputs.at(count).getTimeStamp() << ", " << this->_outputs.at(count).getXPos() << ", " << this->_outputs.at(count).getYPos() << ", " << this->_outputs.at(count).getTireAngle() << ", " << this->_outputs.at(count).getHeading() << endl;
	}

	return;
}

// Adds a new state to the output vector list
void DataSink::AddOutput(State addState) {
	_outputs.push_back(addState);
	return;
}