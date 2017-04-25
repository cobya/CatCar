/**************************************************************************************************/

/*
* File: Input.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: Input.cpp contains the functions responsible for editing and viewing the Input class used for data input
*
*/

/**************************************************************************************************/

using namespace std;

#include"Input.h"

// Constructor for Input object with specified values
Input::Input(double vel, double tireAngleRate, double timestamp) {
	this->setVelocity(vel); // Sets velocity
	this->setTireAngleRate(tireAngleRate); // Sets TireAngleRate
	this->setTimeStamp(timestamp); // Sets the timestamp
	return;
}

// Empty input object
Input::Input() {
	this->setVelocity(0); // Sets velocity to default 0
	this->setTireAngleRate(0); // Sets TireAngleRate to default 0
	this->setTimeStamp(0); // Sets TimeStamp to default 0
	return;
}

// sets the _velocity
void Input::setVelocity(double vel) {
	if (vel >= 0 && vel <= 30) { // If within specified range, set velocity
		this->_velocity = vel;
	}
	else { // Else set to -1 for validity check
		this->_velocity = -1;
	}
	return;
}

// sets the _tire_angle_rate
void Input::setTireAngleRate(double angle) {
	if (angle <= MAX_TIRE_ANGLE_RATE && angle >= MIN_TIRE_ANGLE_RATE) { // If within paramaters, set tire angle rate
		this->_tire_angle_rate = angle;
	} 
	else { // Else set to -1 for validity check
		this->_tire_angle_rate = -1;
	}
	return;
}

// sets the _timestamp
void Input::setTimeStamp(double timestamp) {
	this->_timestamp = timestamp;
	return;
}