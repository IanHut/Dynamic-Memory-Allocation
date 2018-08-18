// Filename: Dynamic Memory Allocation
//
// These are notes and sandbox code for the CS50 2018 Week 3 short video
// entitled "Dynamic Memory Allocation".
//
// Date: 08/17/2018
//
// Name: Ian Hutcheson
//
// IDE: Microsoft Visual Studio 2017


#include <stdio.h>
#include <stdlib.h>

void main() {
	// What if we don't know how much memory we need at compile time?
	// Or what if the program is going to run for a long time and get
	//     an unknown amount of user input?

	// We can use pointers to get access to a block of dynamically allocated 
	//     memory at runtime (rather than compile time)
	// That memory comes from the heap
	
	// Anytime you give a variable a name, it lives on the stack
	// If you use memory you didn't give a name, it lives on the heap
	// Stack and heap are one shared pool of memory

	// How you get dynamically allocated memory?
	// make a call to malloc(), passing as its parameter the number of bytes needed
	// If malloc() successfully obtained that memory, it will return a pointer
	//     to that memory
	// If malloc() CAN'T give you memory, it gives you back a NULL pointer
	// Always always check the pointer malloc gives you and make sure it != NULL
	// type* malloc(size);
	// Allocates a block of size bytes of memory, returning a pointer to the beginning of the block.
	//     size equals the sizeof(type) times the number of elements of that type

	// statically obtain an integer?
	int x = 5;
	// declares an integer named x that lives on the stack

	// dynamically obtain an integer?
	int *px = malloc(sizeof(int)); 
	// obtains 4 bytes of memory from the heap and assigns it to the pointer px

	// get an array of floats on the stack?
	float stackArray[5]; // where 5 is the number of elements in the array
	printf("the array of floats called stackArray points to the location in stack memory: %d\n");

	// get an array of floats
	float* heapArray = malloc(5 * sizeof(float));
	printf("the array of floats called heapArray points to the location in heap memory: %d\n", heapArray);
	// Can now use heapArray[x] bracket notation because arrays are just pointers

	// Problems with dynamically allocated memory?
	// Dynamically-allocated memory is not automatically returned to the system
	// Failing to return memory back results in a memory leak
	// Can hurt your system performance
	// There's certain web browsers that have memory leaks that don't get fixed lol

	// After you malloc() memory, you need to tell the system you're done with that memory
	// How to get it back? free();
	// free() is a function that accepts an argument of a pointer to memory

	char* word = malloc(50 * sizeof(char));
	// allocates 50 chars worth of memory and returns the location of that memory
	//     to the pointer-to-char called 'word'
	// do stuff with word....
	// then once you're done, free up that memory
	free(word);

	// THREE GOLDEN RULES
	// 1. every block of memory you malloc() must eventually be free()'d
	// 2. only memory that you malloc() should be free()'d!! don't free static memory!
	// 3. don't free() something twice!!

	int m; // creates one box: an integer variable called m
	int* a; // creates one box: a pointer-to-int variable called a
	// both of these live on the stack

	int* b = malloc(sizeof(int));
	// this actually creates two boxes
	// creates a box on the heap the size of one int
	// creates a box called b that points to the box on the heap
	// the box on the heap doesn't actually have a name!

	a = &m; // as defined above, a is a pointer-to-int
	// a gets m's address (a points to m)

	a = b;
	// switch a from pointing to the integer box m to the integer box b
	// this means a points to the same address that b points to
	// Note: a doesn't point to b! that would be a = &b

	m = 10;
	// sets the value of m to 10

	*b = m + 2;
	// deference b and put some value in that memory location
	// 10 + 2
	// go to the memory address b points to and assign to it the value of 12

	free(b);
	// deletes b, gives it back to the system
	// at this point, a and b now points to memory we're not supposed to touch!
	// segmentation fault

	// reference & and dereference * operator
	// study those

	return;
}