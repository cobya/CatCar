/**************************************************************************************************/

/*
* File: Vehicle.h
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: Vehicle.h contains the Vehicle class which contains the vehicle's current State and its functions
*
*/

/**************************************************************************************************/

using namespace std;

#ifndef VEHICLE_H
#define VEHICLE_H

#include "State.h"
#include "Input.h"

// wheelbase length in meters
#define L 2.6187

/* Vehicle class which contains the current state of the vehicle including its position, heading, timestamp, and tire angle */
class Vehicle {
	private:
		State _state; // the current state of the vehicle
		void setState( State x ); // sets the value for _state

	public:
		Vehicle(); // constructs a new Vehicle object with the default State value
		void stateUpdate( Input u, double duration ); // Updates the state with specified Input u and duration
		State getState( ) const; // gets the value for _state
};

#endif // VEHICLE_H
