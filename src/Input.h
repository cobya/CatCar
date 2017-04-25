/**************************************************************************************************/

/*
* File: Input.h
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: Input.h contains the Input class which is used for getting input data and the function prototypes for its operation
*
*/

/**************************************************************************************************/

using namespace std;

#ifndef INPUT_H
#define INPUT_H

// M_PI and other variables are defined in here
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

// the MAX and MIN values for tire angle are used in the setTireAngle method
#define MAX_TIRE_ANGLE_RATE 0.5236
#define MIN_TIRE_ANGLE_RATE -0.5236

/* The Input class serves as the default class for values which are being read in from the specified input file and as a part of the State updater*/
class Input{
	private:
		double _velocity; // commanded vehicle velocity (u1)
		double _tire_angle_rate; // commanded tire angle rate (u2)
		double _timestamp; // time stamp at which this command is valid
	
	public:
		Input(double vel, double tireAngleRate, double timestamp); // constructs a new Input object with these initial values
		Input(); // constructs an empty Input object
		
		double getVelocity() const { // returns the _velocity
			return this->_velocity;
		}; 
		void setVelocity(double vel); // sets the _velocity
		
		double getTireAngleRate() const { // returns the _tire_angle_rate
			return this->_tire_angle_rate;
		}; 
		void setTireAngleRate(double angle); // sets the _tire_angle_rate
		
		double getTimeStamp() const { // gets the _timestamp
			return this->_timestamp;
		}; 
		void setTimeStamp(double timestamp); // sets the _timestamp
};

#endif // INPUT_H
