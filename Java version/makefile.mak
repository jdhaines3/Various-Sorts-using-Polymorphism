# Honor Pledge: I pledge that I have neither 
# given nor receieved any help on this assignment.
# Assignment 6: Polymorphism
# Java Makefile
# David Haines

Driver.class: Driver.java
	javac Driver.java
	
Sort.class: Sort.java
	javac Sort.java
	
Bubble.class: Bubble.java
	javac Bubble.java

Insertion.class: Insertion.java
	javac Insertion.java
	
clean:
	rm *.class