/* 
*Honor Pledge: I pledge that I have neither 
*given nor receieved any help on this assignment.
*Assignment 6: Polymorphism
*Insertion Sort Class
*David Haines 
*/


///---Insertion Sort Class---///
public class Insertion extends Sort
{
	//adding default constructor for good habit
	public Insertion()
	{
	}
	
	//automatic overriding of Sort class's sortArray function
	public void sortArray(int numb[])
	{
		//needs variables for index, swap counter, and temp variable
		int index = 1;
		int j;
		int temp;
	
		//index starts at one because first element is already "sorted"; j is set to index whenever index incremented
		for (index; index < 50; index++)
		{
			j = index;
		
			/*	
			*j will check to see if element at current index bigger than last, if it is, swap and decrement j
			*it will continue checking the previous element swapping until j gets to 1 OR the previous element
			*is greater than the one at index j 
			*/
			
			while( j >= 1 && numb[j - 1] > numb[j] )
			{
				//perform swap: see notes in Bubble.cpp
				temp = numb[j];
				numb[j] = numb[j - 1];
				numb[j - 1] = temp;
			
				//decrement j to check if previous number in sorted sub-array is less
				j = j - 1;
			}
		}
	}
}

//basically same as C++ version
