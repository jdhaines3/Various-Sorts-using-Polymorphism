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
			
			///---Second Menu---///
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
					insSort->sortArray(numbers);
					
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
					bubSort->sortArray(numbers);
					
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
	
	return;
 }
 
 
 ///---Load File Function---///
 void Driver::loadFile()
 {	
	//Extracted line variable
	std::string line;
	//create int that will be the converted input string
	int number;
	//create string that holds individual number in csv file
	std::string strInt = "";
	
	//Stringstream instance for reading in and delimiting
	std::stringstream ss;
	//Stringstream instance for converting
	std::stringstream converter;
	
	//Input Stream Variable (opens file, too)
	std::ifstream inputFile("data.txt");
	
	
	//see if it is open; if so, read in numbers and place in array
	if (inputFile.is_open())
	{		
		
		//--while loop to get each line--//
		while (std::getline(inputFile, line))
		{
			//clear ss object and ready it for use
			ss.clear();
			ss.str("");
			
			//set ss object to take in current line
			ss.str(line);
			
			//declare numbers array index variable
			int i = 0;
			
			//--second while loop to parse through comma delimited values--//
			/*
			*Takes in ss value (read-in line), sepearates field based on commas in line,
			*loops through all fields, sets strInt to field value, convert and put in array,
			*then moves to next field
			*/
			while (std::getline(ss, strInt, ','))
			{
				//clear converter from last field value
				converter.clear();
				converter.str("");
			
				//convert string to decimal/int: take in the string variable for each csv field, put out into int variable
				converter << strInt;
				converter >> number;
				
				//set the output number to array element with index i and increment i
				numbers[i] = number;
				i++;
			}
		}
		
		//close the input stream
		inputFile.close();
		
		//print array with array concatenation function	
		std::cout << "" << std::endl;
		std::cout << "File imported." << std::endl;
		std::cout << "Unsorted Array: " << arrayConcat() << std::endl;
		
	}
	else
	{
		//if file can't be opened, print message to user.
		std::cout << "Unable to open file" << std::endl;
	}
	
	return;
 }

 
 ////----Array String Concatenation For Printing----////
 std::string Driver::arrayConcat()
 {
	//variable for index
	int index = 0;
	
	//variable for array string concat
	std::string concatArray = "";
	
	//create stringstream to input number at array index then convert to str
	std::stringstream arrayNum;
	
	//convert int at numbers[i] to a string, add it to the string of all array numbers with a comma and space after
	for (index; index < 50; index++)
	{
		//clear stringstream
		arrayNum.clear();
		arrayNum.str("");
		
		//take in the number at index
		arrayNum << numbers[index];
		
		//set string to arrayNum 
		std::string s = arrayNum.str();
		
		/*
		*std::string s = std::to_string (numbers[index]);
		*DOESN'T WORK WITH THIS COMPILER
		*/
		
		//add the array element to the string with a comma and space divider
		concatArray = concatArray + s + ", ";
	}

	//erase last comma and space in strArray
	std::string strArray = concatArray.substr(0, strArray.length() - 2);

	//return string with all array elements concatenated, without last space and comma
	return strArray;
 }
 
 ////----MAIN Program----////
 int main()
 {
	//create new instance of driver and call the main (run) function
	Driver * drive = new Driver();
	drive->run();
	
	//delete drive when done and return 0
	delete drive;
	return 0;
 }