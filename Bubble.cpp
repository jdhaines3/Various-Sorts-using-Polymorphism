/* Honor Pledge: I pledge that I have neither 
 given nor receieved any help on this assignment.
Assignment 6: Polymorphism
 C++ Bubble CPP
 David Haines */
 
 #include "Bubble.h"
 
 ///---Bubble Sort Virtual Function---///
 void Bubble::sortArray(int numb[])
 {
	//declare index variable
	int index = 0;
	//declare temp variable for swapping
	int temp;
	//declare second loop index variable
	int j = 0;
	
	
	//for loop to go through each element in array and move the highest number up; iterator loop
	for (index; index < 50; index++)
	{
		
		/*but must include second for loop to go through the rest of the numbers left behind
		this loop will leave off last "bubbled" element and sort the highest number to the end then repeat*/
		for (j; j < n - index - 1; j++)
		{
			
			//determine if current index is larger than next index
			if (numb[j] > numb[j + 1])
			{
				//must have temp variable as placeholder for the current element in array to perform the swap
				temp = numb[j];
				//set current index int to next index's int
				numb[j] = numb[j + 1];
				//set the next element to the greater int stored in the temp variable
				numb[j + 1] = temp;
			}
		}
	}
 }