/**************************************************************************************************/

/*
* File: Director.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: Director.cpp contains the Execute function which converts the inputted data into its output format
*
*/

/**************************************************************************************************/

using namespace std;

#include"Director.h"

Director::Director() {
	// Empty constructor
	return;
}

// Creates the director class using a specified DataSource and DataSink class
Director::Director(DataSource* dsource, DataSink* dsink) {
	_dsource = dsource;
	_dsink = dsink;
	return;
}

// Executes the state updates for the vehicle class based on the input vector
void Director::Execute() {
	int i = 0;

	if (_dsource->AreInputsValid() == false) { // If the inputs are not valid, do not run
		return;
	}
	else if (_dsource->GetInputs().size() == 0){ // If there are no inputs, don't run
		return;
	}

	while (_dsource->GetInputs().size() > (unsigned)i) { // While there are still more inputs to process, continue
		if ((unsigned)i != _dsource->GetInputs().size() - 1) { // If not the last input, find duration and update state
			_catcar.stateUpdate(_dsource->GetInputs().at(i), _dsource->GetInputs().at(i + 1).getTimeStamp() - _dsource->GetInputs().at(i).getTimeStamp());
		} 
		else {
			_catcar.stateUpdate(_dsource->GetInputs().at(i), 0.2); // If it is the last state, set duration to .2s and update state
		}

		i++;
		_dsink->AddOutput(_catcar.getState()); // Add the new state to the list of outputs
	}

	return;
}
