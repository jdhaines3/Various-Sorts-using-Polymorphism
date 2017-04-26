/* Honor Pledge: I pledge that I have neither 
 given nor receieved any help on this assignment.
Assignment 6: Polymorphism
 C++ Header file
 David Haines */
 
 //imports/includes for classes
 #include "Driver.h"
 #include "Sort.h"
 #include "Bubble.h"
 #include "Insertion.h"
 
 //imports/includes for operations
 #include <fstream>
 #include <sstream>
 #include <string>
 #include <stdlib.h>
 #include <iostream>
 
 
 ////----Driver Main Function----////
 void Driver::run()
 {
	//exit loop variable
	int menuOne = 0;
	
	///---First Menu---///
	while (menuOne == 0)
	{
		//input variable declaration
		std::string input = "";
		
		//print menu and ask user to enter which one they would like to do
		std::cout << "" << std::endl;
		std::cout << "1) Load Data (From File)" << std::endl;
		std::cout << "2) Exit Program" << std::endl;
		std::cout << "Please Enter Your Selection: " << std::endl;
		std::cin >> input;
		
		//if, else if statement for determining which option user wanted;
		//if user entered incorrect entry, tell them to re-enter their selection
		if (input == "1")
		{
			//run loadFile function to load in the text file and convert string to numbers
			loadFile();
			
			//exit loop variable for second menu
			int menuTwo = 0;
			
			//--Second Menu--//
			while (menuTwo == 0)
			{
				//second menu input variable declaration
				std::string inputTwo = "";
				
				//print menu and ask user to enter which one they would like to do
				std::cout << "" << std::endl;
				std::cout << "1) Insertion Sort" << std::endl;
				std::cout << "2) Bubble Sort" << std::endl;
				std::cout << "3) Exit Program" << std::endl;
				std::cout << "Please Enter Your Selection: " << std::endl;
				std::cin >> inputTwo;
				
				//determine which option user selected, or if entry was invalid; do said option
				if (inputTwo == "1")
				{
					//create Insertion object
					Sort * insSort = new Insertion();
					
					//call the sort Array method//
					insSort->sortArray(numbers[50]);
					
					//print sorted array
					std::cout << "" << std::endl;
					std::cout << "Insertion Sort: " << arrayConcat() << std::endl;
					
					//delete Insertion Sort
					delete insSort;
					
					//back to main menuOne
					menuTwo = 1;
				}
				else if (inputTwo == "2")
				{
					//create Bubble object
					Sort * bubSort = new Bubble();
					
					//call the sort Array method//
					bubSort->sortArray(numbers[50]);
					
					//print sorted array
					std::cout << "" << std::endl;
					std::cout << "Bubble Sort: " << arrayConcat() << std::endl;
					
					//delete Bubble sort object
					delete bubSort;
					
					//back to first menu
					menuTwo = 1;
				}
				else if (inputTwo == "3")
				{
					//exit both menus/program
					menuOne = 1;
					menuTwo = 1;
				}
				else
				{
					//invalid input, give message and go back to second menu start
					std::cout << "" << std::endl;
					std::cout << "I'm not sure what you were trying to do." << std::endl;
					std::cout << "Please try entering 1, 2, or 3."  << std::endl;
				}
			}
		}
		else if (input == "2")
		{
			//exit while loop/program
			menuOne = 1;
		}
		else 
		{
			std::cout << "" << std::endl;
			std::cout << "I'm not sure what you were trying to do." << std::endl;
			std::cout << "Please try entering 1 or 2."  << std::endl;
		}
		
		//exit message
		std::cout << "Ok, exiting now. Goodbye!" << std::endl;
	}
 }
 
 
 //--Load File Function--//
 void Driver::loadFile()
 {
	 
	//create string stream and string variable that inputfile extracts to
	std::string line = "";
	std::stringstream ss(line);
	
	//create conversion stream and placeholder string
	std::string convert = "";
	std::stringstream converter(convert);
	
	//clear contents and get it ready to use
	//might have to move to while loop
	ss.clear();
	ss.str("");
	
	//create string that holds individual number in csv file
	std::string stringNumber = "";
	
	//create int that will be the converted string
	int number = 0;
	
	//get file and read in
	std::ifstream inputFile("data.txt");
	
	//see if it is open; if so, read in numbers and place in array
	if (inputFile.is_open())
	{
		while (std::getline(inputFile, line))
		{
			//get line from file and specify comma delimiter
			std::getline(ss, stringNumber, ',');
			
			//clear converter
			converter.clear();
			converter.str("");
			
			//convert string to decimal/int
			converter << stringNumber;
			converter >> std::dec >> number;
			
			numbers[i] = number;
			i++;
		}
		
		//print array	
		std::cout << "" << std::endl;
		std::cout << "File imported." << std::endl;
		std::cout << "Unsorted Array: " << arrayConcat() << std::endl;
		
	}
	else
	{
		std::cout << "Unable to open file" << std::endl;
	}
 }

 
 ////----Array String Concatenation For Printing----////
 std::string Driver::arrayConcat()
 {
	//variable for index
	int index = 0;
	//variable for array string concat
	std::string concatArray = "";
		
	for (index; index < 50; index++)
	{
		//convert int at numbers[i] to a string, add it to the string of all array numbers with a comma and space after
		std::string s = std::to_string (numbers[i]);
		concatArray = concatArray + s + ", ";
	}
		
	//erase last comma and space in strArray
	std::string strArray = concatArray.substr(0, strArray.length() - 2);

	//return string with all array elements concatenated, without last space and comma
	return strArray
 }
 
 //run program
 int main()
 {
	Driver * runner = new Driver();
	runner->run();
	delete runner();
	return 0;
 }