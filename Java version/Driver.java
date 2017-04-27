/* 
*Honor Pledge: I pledge that I have neither 
*given nor receieved any help on this assignment.
*Assignment 6: Polymorphism
*Driver Class
*David Haines 
*/

///---Imports---///
//import java io for file input readers, exceptions, and possible formatted output (might just use system.out)
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;

///---Driver Class---///
public class Driver
{
	//declare numbers array as private static
	public static int[] numbers = new int[50];
	
	
	///---Main---///
	public static void main(String[] args)
	{
		//exit loop variable
		int menuOne = 0;
	
		///---First Menu---///
		while (menuOne == 0)
		{
			//Set up scanner input for first menu
			Scanner input = new Scanner(System.in);
		
			//print menu and ask user to enter which one they would like to do
			System.out.println("");
			System.out.println("1) Load Data (From File)");
			System.out.println("2) Exit Program");
			System.out.printf("%nPlease Enter Your Selection: ");
			String in = input.next();
		
			//if, else if statement for determining which option user wanted;
			//if user entered incorrect entry, tell them to re-enter their selection
			if (in.equals("1"))
			{
				//run loadFile function to load in the text file and convert string to numbers
				loadFile();
			
				//exit loop variable for second menu
				int menuTwo = 0;
			
				///---Second Menu---///
				while (menuTwo == 0)
				{
					
					//Set up scanner input for first menu
					Scanner inputTwo = new Scanner(System.in);
				
					//print menu and ask user to enter which one they would like to do
					System.out.println("");
					System.out.println("1) Insertion Sort");
					System.out.println("2) Bubble Sort");
					System.out.println("3) Exit Program");
					System.out.printf("%nPlease Enter Your Selection: ");
					String inp = inputTwo.next();
				
					//determine which option user selected, or if entry was invalid; do said option
					if (inputTwo.equals("1"))
					{
						//create Insertion object
						Sort insSort = new Insertion();
					
						//call the sort Array method//
						insSort.sortArray(numbers);
					
						//print sorted array
						System.out.printf("%nInsertion Sort: %s%n", arrayConcat());
					
						//back to main menuOne
						menuTwo = 1;
					}
					else if (inputTwo.equals("2"))
					{
						//create Bubble object
						Sort bubSort = new Bubble();
					
						//call the sort Array method//
						bubSort.sortArray(numbers);
					
						//print sorted array
						System.out.printf("%nBubble Sort: %s%n", arrayConcat());
					
						//back to first menu
						menuTwo = 1;
					}
					else if (inputTwo.equals("3"))
					{
						//exit both menus/program
						menuOne = 1;
						menuTwo = 1;
					}
					else
					{
						//invalid input, give message and go back to second menu start
						System.out.println("");
						System.out.println("I'm not sure what you were trying to do.");
						System.out.println("Please try entering 1, 2, or 3.");
					}
				}
			}
			else if (in.equals("2"))
			{
				//exit while loop/program
				menuOne = 1;
			}
			else 
			{
				System.out.println("");
				System.out.println("I'm not sure what you were trying to do.");
				System.out.println("Please try entering 1 or 2.");
			}
		}
	
		//exit message
		System.out.println("");
		System.out.println("Ok, exiting now. Goodbye!");
		System.out.println("");
	}
 
 
	///---Load File Function---///
	public static void loadFile()
	{	
		try
		{
			//input stream for text file, input stream reader then buffer reader
			InputStream inpStrm = new FileInputStream("data.txt");
			
			InputStreamReader isr = new InputStreamReader(inpStrm);
			
			BufferedReader br = new BufferedReader(isr);
			
			//burn first line of file (header)
			String line = br.readLine();		
		
			//--while loop to get each line--//
			while (line != null)
			{
				//put line split into numbers array
				String numbs[] = line.split(",");
			
				//--second while loop to convert string array to int array--//
			
				for (int i = 0; i < numbs.length; i++)
				{
					//parse the string in index i spot for an int, put that value in int numbers array with same index
					numbers[i] = Integer.parseInt(numbs[i]);
				}
				
				//get next line
				line = br.readLine();
			}
		
			//close the input stream
			br.close();
		
			//print array with array concatenation function	
			System.out.println("");
			System.out.println("File imported.");
			System.out.printf("%nUnsorted Array: %s%n", arrayConcat());
		
		}
		catch (IOException ex)
		{
			//if file can't be opened, print message to user.
			System.out.println("Unable to open file");
			System.err.println(ex);
		}
	
	}

 
	////----Array String Concatenation For Printing----////
	public static String arrayConcat()
	{
	
		//variable for array string concat
		String concatArray = "";
	
		//convert int at numbers[i] to a string, add it to the string of all array numbers with a comma and space after
		for (int index = 0; index < 50; index++)
		{
			int i = numbers[index];
		
			//add the array element to the string with a comma and space divider
			concatArray = concatArray + String.valueOf(i) + ", ";
		}

		//erase last comma and space in strArray
		String strArray = concatArray.substring(0, concatArray.length() - 2);

		//return string with all array elements concatenated, without last space and comma
		return strArray;
	}
}