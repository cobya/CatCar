/**************************************************************************************************/

/*
* File: Director.h
* Author: Coby Allred
* NetID: cobyallred
* Date: 10/27/16
*
* Description: The Director.h file contains the Director class which is responsible for running the program's main functions
*
*/

/**************************************************************************************************/

using namespace std;

#ifndef DIRECTOR_H
#define DIRECTOR_H

#include<stdio.h>
#include"DataSink.h"
#include"DataSource.h"
#include"Vehicle.h"

/* The Director class which is responsible for executing the program's main code features */
class Director {
	public:
		Director(); // Empty director constructor
		Director(DataSource* dsource, DataSink* dsink); // Constructs a director with a specified DataSource and DataSink
	
		void Execute(); // Executes the main code functions

	private:
		Vehicle _catcar; // Vehicle states
		DataSource* _dsource; // The DataSource class
		DataSink* _dsink; // The DataSink class
};

#endif