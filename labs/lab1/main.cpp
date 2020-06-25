/**
 * UCR CS&E
 * CS014 Lab 1
 * main.cpp
 */

#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Node.h"

#define fibo_number 11

int fibonacci(int n);

using namespace std;

int main()
{
	/*
	// Instantiate two Lists 
	List myList;
	List myList2;
	
	// Try to print an empty List 
	cout << "\nTest printing an empty list:";
	myList.print();
	
	cout << "\nPushing back first " << fibo_number << " Fibonacci numbers:";
	for(int i = 0; i < fibo_number; i++)
	{
		myList.push_back(fibonacci(i));
		myList.print();
	}
	
	cout << "\nReverse myList pushing front contents of myList into myList2:";
	for(Iterator iter = myList.begin(); !iter.is_equal(myList.end()); iter.next_pos())
	{
		myList2.push_front(iter.get_value());
		myList2.print();
	}
		
		
		
*/
//==========================================
//		TEST
//==========================================

List list;
cout << "Making a list of even numbers 0-10" << endl;
for(int i = 0; i <= 5; i++){
	list.push_back(i * 2);
}
list.print();

cout << "Test1: print_reverse" << endl;
list.print_reverse();

cout << "Test2: sorted_insert (inserting 1, 3, and 5)" << endl;
list.sorted_insert(1);
list.sorted_insert(3);
list.sorted_insert(5);
list.print();

cout << "Test3: insert_after (0, 0), (1, 1), (3, 2)" << endl;
cout << "Your list should be: 0, 0, 1, 1, 2, 2, 3, 4, 5, 6, 8, 10" << endl;
list.insert_after(0,0);
//list.print();
list.insert_after(1,1);
//list.print();
list.insert_after(3,2);
list.print();

cout << "Test4: insert_before (6,3), (8,4), (11,5)" << endl;
cout << "Your list should be: 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 8, 10" << endl;
list.insert_before(6,3);
list.insert_before(8,4);
list.insert_before(11,5);
list.print();

cout << "Test5: count" << endl;
cout << "counting -1 -> Output should be 0" << endl;
cout << list.count(-1) << endl;
cout << "counting 0 -> Output should be 2" << endl;
cout << list.count(0) << endl;
cout << "counting 8 -> Output should be 1" << endl;
cout << list.count(8) << endl;

cout << "First tests done" << endl;

cout << "\n---------EMPTY CASE---------\n" << endl;
List list2;
List list3;
List list4;
cout << "list2:";
list2.print();
cout << "list3:";
list3.print();
cout << "list4:";
list4.print();

cout << "Empty test: print_reverse" << endl;
list2.print_reverse();

cout << "Empty test: count" << endl;
cout << "Counting 0 -> should return 0" << endl;
cout << list2.count(0) << endl;


cout << "Empty test: sorted_insert(2)" << endl;
list2.sorted_insert(2);
cout << "list2 should contain 2" << endl;
list2.print();

cout << "Empty test: insert_after(0,3)" << endl;
list3.insert_after(0,3);
cout << "list2 should contain 3" << endl;
list3.print();

cout << "Empty test: insert_before(0,4)" << endl;
list4.insert_before(0,4);
cout << "list2 should contain 4" << endl;
list4.print();


cout << "\n---------EDGE CASE---------\n" << endl;
cout << "Test1: sorted_insert 1,2,and 3" << endl;
cout << "list2 should be 1, 2, 2, 3" << endl;
list2.sorted_insert(1);
list2.sorted_insert(2);
list2.sorted_insert(3);
list2.print();

cout << "Test2: insert_after (-1,5), (0,4), (2,6), (10, 7)" << endl;
cout << "list3 should be 3, 4, 5, 6, 7" << endl;
list3.insert_after(-1,5);
list3.insert_after(0,4);
list3.insert_after(2,6);
list3.insert_after(10,7);
list3.print();

cout << "Test3: insert_before (-1,2), (0,1), (2,3) (10,7)" << endl;
cout << "list4 should be 1, 2, 3, 7, 4" << endl;
list4.insert_before(-1,2);
list4.insert_before(0,1);
list4.insert_before(2,3);
list4.insert_before(10,7);
list4.print();

cout << "END" << endl;


	return 0;
}

/**
 * Local Fibonacci function for filling and testing Lists 
 * @param n the Fibonacci number to calculate
 * @return fibonacci(n)
 */
int fibonacci(int n)
{
	if((n == 0) | (n == 1))
	{
		return n;
	}
	else
	{
		return fibonacci(n-2) + fibonacci(n-1);
	}
}


