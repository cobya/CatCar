/*******************************************************************************************/

/*
* File: vehicle.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: Vehicle.cpp implements the Vehicle constructor and the functions to update the vehicle's state
*
*/

/*******************************************************************************************/

using namespace std;

#include "Vehicle.h"
#include <cmath>

Vehicle::Vehicle() {
	// Setting the vehicle's state values to initial 0
	_state.setHeading(0.0); 
	_state.setTimeStamp(0.0);
	_state.setTireAngle(0.0);
	_state.setXPos(0.0);
	_state.setYPos(0.0);
	return;
}

void Vehicle::setState(State x) {
	this->_state = x;
	return;
}

void Vehicle::stateUpdate(Input u, double duration) {
	
	double x = _state.getXPos() + (duration * u.getVelocity() * cos(_state.getTireAngle()) * cos(_state.getHeading())); // calculating x1, the x position
	double y = _state.getYPos() + (duration * u.getVelocity() * cos(_state.getTireAngle()) * sin(_state.getHeading())); // calculating x2, the y position
	double heading = _state.getHeading() + (duration * u.getVelocity() * (1.0/L) *sin(_state.getTireAngle())); // calculating x4, the heading of the vehicle
	double tireangle = _state.getTireAngle() + (duration * u.getTireAngleRate()); // calculating x3, the tire angle
	

	this->_state.setXPos(x); // set state's new x position
	this->_state.setYPos(y); // set state's new y position
	this->_state.setHeading(heading); // set state's new heading
	this->_state.setTireAngle(tireangle); // set state's new tire angle
	this->_state.setTimeStamp(_state.getTimeStamp() + duration); // set state's new timestamp

	return;
}

State Vehicle::getState() const {
	return this->_state;
}