/**
 * UCR CS&E
 * CS014 Lab 1
 * List.cpp
 */

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}


//======================================================================================
// Implemented Below

void List::sorted_insert(int value){
	/*functions inserts new node with value into list. This insert_sort should preserve the increasing ordering of the list. 
	For example, if value == 5, then the new node would have a value of 5 and be inserted after the last instance 
	(furthest from head node) of a existing node with value 5. To test create a list object with sorted values. 
	NOTE: When inserting at the front or back of list, 
	you can call pushfront and pushback in the body of the sortedinsert function. DO NOT, however, call pushback or push_front directly in main function.*/
	if(!head){ // list is empty
		push_back(value);
		return;
	}
	if(head->get_value() > value){ // inserting at the tail
		push_front(value);
		return;
	}
	
	Node* curr = 0;
	for(Iterator iter = begin(); iter.get_value() <= value; iter.next_pos()){
		if(iter.get_curr_pos()->get_next()){
			curr = iter.get_curr_pos();
		}
		else{
			push_back(value);
			return;
		}
	}
	
	Node* curr_next = curr->get_next();
	Node* newNode = new Node(value);
	
	curr->set_next(newNode);
	newNode->set_prev(curr);
	newNode->set_next(curr_next);
	curr_next->set_prev(newNode);
	
}
void List::print_reverse()const{
	/*function prints the contents of a list backwards. NOTE: Implement a void Iterator::prev_pos() function to make for use in this function.*/
	cout << "\nList contents in reverse:\n";

	/* list is empty */
	if(!tail)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = rbegin(); !iter.is_equal(rend()); iter.prev_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

void List::insert_after(int i, int value){ // NEED TO FIX /can access nullptr->prev
/*function inserts a new node with value at position i + 1 in the list. 
If position passed in is outside of the list’s current boundaries (i < 0 or i > size - 1), 
have a policy to handle this.*/
	if(!head){
		push_front(value);
		return;
	}
	
	Node* curr = head;
	
	if(i < 0){
		if(!curr->get_next()){
			push_back(value);
			return;
		}
		else{
			curr = head;
		}
	}
	else{
		for(Iterator iter = begin(); i > 0; i--){
			//
			if(!curr->get_next()){
				push_back(value);
				return;
			}	
			iter.next_pos();
			curr = iter.get_curr_pos();
		}
		if(!curr->get_next()){
			push_back(value);
			return;
		}	
	}
	
	Node* curr_next = curr->get_next();
	Node* newNode = new Node(value);
	
	curr->set_next(newNode);
	newNode->set_prev(curr);
	newNode->set_next(curr_next);
	curr_next->set_prev(newNode);
}

void List::insert_before(int i, int value){
	/*function inserts a node with specified value at position i­ - 1 in the list. 
	If position passed in is outside of the list’s current boundaries (i < 0 or i > size - 1), 
	have a policy to handle this*/
	if(!head){
		push_front(value);
		return;
	}
	
	Node* curr = head;
	
	if(i < 0){
		push_front(value);
		return;
	}
	for(Iterator iter = begin(); i > 0; i--){
		if((iter.get_curr_pos()->get_next())){
			iter.next_pos();
			curr = iter.get_curr_pos();
		}
	}
	if(!curr->get_prev()){
		push_front(value);
		return;
	}
	Node* curr_prev = curr->get_prev();
	Node* newNode = new Node(value);
	
	curr_prev->set_next(newNode);
	newNode->set_prev(curr_prev);
	newNode->set_next(curr);
	curr->set_prev(newNode);
}

int List::count(int value)const{
	/*function returns the number of times value appears in the list.*/
	int cnt = 0;
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()){
		if(iter.get_value() == value){
			cnt++;
		}
	}
	return cnt;
}

//=================================================================
//Helper Fxns

Iterator List::rbegin()const
{
	Iterator iter;
	iter.set_curr_pos(get_tail());
	iter.set_last_pos(get_head());
	return iter;
}


Iterator List::rend()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_head());
	return iter;
}




//===================================================================
void List::insert_after2(int i, int value){ // NEED TO FIX /can access nullptr->prev
/*function inserts a new node with value at position i + 1 in the list. 
If position passed in is outside of the list’s current boundaries (i < 0 or i > size - 1), 
have a policy to handle this.*/
	if(!head){
		push_front(value);
		return;
	}
	
	Node* curr = head;
	
	if(i < 0){
		if(!curr->get_next()){
			push_front(value);
			return;
		}
		else{
			curr = head;
		}
	}
	else{
		for(Iterator iter = begin(); i > 0; i--){
			//
			if(!curr->get_next()){
				push_back(value);
				return;
			}	
			iter.next_pos();
			curr = iter.get_curr_pos();
		}
		if(!curr->get_next()){
			push_back(value);
			return;
		}	
	}
	
	Node* curr_next = curr->get_next();
	Node* newNode = new Node(value);
	
	curr->set_next(newNode);
	newNode->set_prev(curr);
	newNode->set_next(curr_next);
	curr_next->set_prev(newNode);
}

void List::insert_before2(int i, int value){
	/*function inserts a node with specified value at position i­ - 1 in the list. 
	If position passed in is outside of the list’s current boundaries (i < 0 or i > size - 1), 
	have a policy to handle this*/
	if(!head){
		push_front(value);
		return;
	}
	
	Node* curr = head;
	
	if(i < 0){
		push_front(value);
		return;
	}
	for(Iterator iter = begin(); i > 0; i--){
		if((iter.get_curr_pos()->get_next())){
			iter.next_pos();
			curr = iter.get_curr_pos();
		}
		else{
			push_back(value);
			return;
		}
	}
	if(!curr->get_prev()){
		push_front(value);
		return;
	}
	Node* curr_prev = curr->get_prev();
	Node* newNode = new Node(value);
	
	curr_prev->set_next(newNode);
	newNode->set_prev(curr_prev);
	newNode->set_next(curr);
	curr->set_prev(newNode);
}