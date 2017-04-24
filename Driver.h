/* Honor Pledge: I pledge that I have neither 
 given nor receieved any help on this assignment.
Assignment 6: Polymorphism
 C++ Header file
 David Haines */
 
 //--Header Guard--//
#ifndef DRIVER_H
#define DRIVER_H

class Driver
{
	//declare class member variables and functions
	public:
		int numbers[];
		int main();
		void loadFile();
		
		//--Constructor--//
		Driver();
		
		//--Destructor--//
		~Driver();
};

#endif