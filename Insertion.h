/* Honor Pledge: I pledge that I have neither 
 given nor receieved any help on this assignment.
Assignment 6: Polymorphism
 C++ Header file
 David Haines */
 
 //--Header Guard--//
#ifndef INSERTION_H
#define INSERTION_H

//include virtual class Sort
#include "Sort.h"

//--Insertion Sort Class--//

//extension of sort
class Insertion : public Sort
{
	//just overrides sortArray; needs no member variables
	//needs constructor and Destructor
	
	public:
		//--Default Constructor--//
		Insertion();
		
		//--Virtual sortArray Function (overwritten)--//
		virtual void sortArray(int []);
		
		//--Destructor--//
		~Insertion();
		
};
//end header guard
#endif