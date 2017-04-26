#Honor Pledge: I pledge that I have neither 
#given nor receieved any help on this assignment.
#Assignment 6: Polymorphism
#C++ Make File
#David Haines

SortArray.exe: Driver.o Bubble.o Insertion.o
	g++ Driver.o Bubble.o Insertion.o -o SortArray.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp

Bubble.o: Bubble.cpp
	g++ -c Bubble.cpp
	
Insertion.o: Insertion.cpp
	g++ -c Insertion.cpp

clean:
	rm -f *.o
	rm SortArray