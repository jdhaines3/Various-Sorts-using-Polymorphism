/* 
*Honor Pledge: I pledge that I have neither 
*given nor receieved any help on this assignment.
*Assignment 6: Polymorphism
*Driver Header File
*David Haines
*/
 
 //--Header Guard--//
#ifndef DRIVER_H
#define DRIVER_H

//include for string type
#include <stdlib.h>
#include <string>

class Driver
{
	//declare class member variables and functions
	public:
		int numbers[50];
		void run();
		void loadFile();
		std::string arrayConcat();
		
		//call constructors and destructors inline as blank
		
		//--Constructor--//
		Driver() {};
		
		//--Destructor--//
		~Driver() {};
};
//end header guard
#endif