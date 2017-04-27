/* 
*Honor Pledge: I pledge that I have neither 
*given nor receieved any help on this assignment.
*Assignment 6: Polymorphism
*Pure Virtual Sort Class Header File
*David Haines 
*/
 
//--Header Guard--//
#ifndef SORT_H
#define SORT_H

//--Header file for Sort--//
class Sort
{
	//must be public and pure virtual : set function to zero
	public:
		virtual void sortArray(int []) = 0;
		
	//add virtual destructor
	virtual ~Sort() {};
		
};

//end header guard
#endif
 