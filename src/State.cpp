/**************************************************************************************************/

/*
* File: State.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: State.cpp contains the functions which update and get the vehicle's current state
*
*/

/**************************************************************************************************/

using namespace std;

#include "State.h"

// Constructs a state object with specified values
State::State(double x1, double x2, double x3, double x4, double timestamp) {
	this->_xpos = x1;
	this->_ypos = x2;
	this->_tire_angle = x3;
	this->_heading = x4;
	this->_timestamp = timestamp;
	return;
}

// constructs an empty State object
State::State() { 
	this->_xpos = 0.0;
	this->_ypos = 0.0;
	this->_tire_angle = 0.0;
	this->_heading = 0.0;
	this->_timestamp = 0.0;
	return;
}

// sets the _xpos
void State::setXPos(double xpos) {
	this->_xpos = xpos;
	return;
}

// sets the _ypos
void State::setYPos(double ypos) {
	this->_ypos = ypos;
	return;
}

// sets the _tire_angle
void State::setTireAngle(double angle) {
	if (angle >= MIN_TIRE_ANGLE && angle <= MAX_TIRE_ANGLE) { // If within the range, set
		this->_tire_angle = angle;
	}
	else if (angle <= MIN_TIRE_ANGLE) { // If less, set as minimum
		this->_tire_angle = MIN_TIRE_ANGLE;
	}
	else if (angle >= MAX_TIRE_ANGLE) { // If greater, set as maximum
		this->_tire_angle = MAX_TIRE_ANGLE;
	}
	return;
}

// sets the _heading
void State::setHeading(double heading) {
	if (heading >= 0 && heading <= M_TWO_TIMES_PI) { // If within range, set
		this->_heading = heading;
	}
	else {
		this->_heading = heading + M_TWO_TIMES_PI; // Othewrwise add 2Pi
	}
	return;
}

// sets the _timestamp
void State::setTimeStamp(double timestamp) {
	this->_timestamp = timestamp;
	return;
}