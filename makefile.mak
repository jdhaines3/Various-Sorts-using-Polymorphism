#Honor Pledge: I pledge that I have neither 
#given nor receieved any help on this assignment.
#Assignment 6: Polymorphism
#C++ Make File
#David Haines

SortArray.exe: Sort.o Bubble.o Insertion.o Driver.o
	g++ Sort.o Bubble.o Insertion.o Driver.o -o SortArray.exe

Sort.o: Sort.cpp
	g++ -c Sort.cpp

Bubble.o: Bubble.cpp
	g++ -c Bubble.cpp
	
Insertion.o: Insertion.cpp
	g++ -c Insertion.cpp
	
Driver.o: Driver.cpp
	g++ -c Driver.cpp

clean:
	rm -f *.o
	rm ClassMadness