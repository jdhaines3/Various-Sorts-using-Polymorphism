#Honor Pledge: I pledge that I have neither 
#given nor receieved any help on this assignment.
#Assignment 6: Polymorphism
#C++ Make File
#David Haines

SortArray.exe: Driver.o Sort.o Bubble.o Insertion.o
	g++ Driver.o Sort.o Bubble.o Insertion.o -o SortArray.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp
	
Sort.o: Sort.cpp
	g++ -c Sort.cpp

Bubble.o: Bubble.cpp
	g++ -c Bubble.cpp
	
Insertion.o: Insertion.cpp
	g++ -c Insertion.cpp

clean:
	rm -f *.o
	rm ClassMadness