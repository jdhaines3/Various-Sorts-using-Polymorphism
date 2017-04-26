/* Honor Pledge: I pledge that I have neither 
 given nor receieved any help on this assignment.
Assignment 6: Polymorphism
 C++ Header file
 David Haines */
 
//--Header Guard--//
#ifndef BUBBLE_H
#define BUBBLE_H

//include virtual class Sort
#include "Sort.h"

//--Bubble Sort Class--//

//extension of sort
class Bubble : public Sort
{
	//just overrides sortArray; needs no member variables
	//needs constructor and Destructor
	
	public:
		//--Default Constructor--//
		Bubble() {};
		
		//--Virtual sortArray Function (overwritten)--//
		virtual void sortArray(int []);
		
		//--Destructor--//
		~Bubble() {};
		
};
//end header guard
#endif