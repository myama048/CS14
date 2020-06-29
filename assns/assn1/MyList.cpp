#include<iostream>
#include<cassert>
#include<algorithm>
#include "MyList.h"
using namespace std;

MyList::MyList(){
    head = nullptr;
}


MyList::MyList(const MyList& str){
/*Copy constructor. Constructs a list from a passed in MyList object,
e.g. MyList l1(l2);. Performs a deep-copy, where memory separate from the argument
object is allocated from the heap, using the keyword new.*/
    head = nullptr;
    for(Node* temp = str.head; temp != nullptr; temp = temp->next){
        push_back(temp->value);
    }
}


MyList::MyList(const string& str){
    /*Constructs a list from a passed in string object, 
    e.g. string username = "FLYNN"; MyList l1(username);.*/
    for(unsigned int i = 0; i < str.size(); i++){
        push_back(str[i]);
    }
}


MyList::MyList(const char* str){
    /*Constructs a list from a passed in string literal, 
    e.g. MyList l1("Red pill, or Blue pill?");*/
    for(unsigned int i = 0; i < sizeof(str); i++){
        push_back(str[i]);
    }
}


MyList::~MyList(){
    Node* curr = 0;
    while(head){
        curr = head;
        head = head->next;
        delete curr;
    }
}

//----------------------------------------------------------------------------------------------------

void MyList::push_front(char value){
    Node* newNode = new Node();
    newNode->value = value;
    if(!head){ // empty
        head = newNode;
    }
    else{ 
        newNode->next = head;
        head = newNode;
    }
}

void MyList::push_back(char value){
    Node* newNode = new Node();
    newNode->value = value;
    if(!head){
        head = newNode;
        return;
    }
    else{
        Node* lastNode = head;
        for(Node* curr = head; curr->next; curr = curr->next){
            lastNode = curr->next;
        }
        lastNode->next = newNode;
    }
}

void MyList::pop_front(){
    /*Removes the first item from the list. No action on empty list.*/
    if(!head){
        //cout << "Error: list is empty" << endl;
        return;
    }
    else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void MyList::pop_back(){
    /*Removes the last item from the list. No action on empty list.*/
    if(!head){ // empty list
        //cout << "Error: list is empty" << endl;
        return;
    }
    else if(!head->next){ // list with 1 node
        delete head;
        head = nullptr;
    }
    else{ // list contains at least 2 nodes
        Node* sec_lastNode = head;
        for(Node* curr = head; curr->next; curr = curr->next){
            sec_lastNode = curr;
        }
        delete sec_lastNode->next;
        sec_lastNode->next = nullptr;
    }
}


void MyList::swap(int i, int j){
    /*Swaps the value of the nodes at positions i and j.
    Program should take no action if i or j is out-of-bounds.*/
    if((i < 0) || (j < 0) || (i + 1 > this->size()) || (j + 1 > this->size())){
        //out-of-bounds
        return;
    }
    //char ival, jval;
    Node* itr_i = head;
    Node* itr_j = head;
    for(int a = 0; a < i; a++){
        itr_i = itr_i->next;
    }
    for(int b = 0; b < j; b++){
        itr_j = itr_j->next;
    }
    
    char cpy = itr_i->value;
    itr_i->value = itr_j->value;
    itr_j->value = cpy;
}


void MyList::insert_at_pos(int pos, char value){
    /*Inserts a node with value at position i in the list. 
    Program should abort via an assert statement if i is out-of-bounds.*/
    
    assert(pos > 0 || pos < size());
    if(pos == 0){
        push_front(value);
        return;
    }
    else if(pos == size()){
        push_back(value);
        return;
    }
    
    Node* curr = head;
    for(int i = 0; i < pos - 1; i++){
        curr = curr->next;
    }
    
    Node* newNode = new Node();
    newNode->value = value;
    
    newNode->next = curr->next;
    curr->next = newNode;
    
    
    return;
}


void MyList::reverse(){
    /*Reverses the items in the list.*/
    Node* rev = 0;
    Node* curr = head;
    Node* follow = 0;
    
    while(curr){
        follow = curr->next;
        curr->next = rev;
        rev = curr;
        curr = follow;
    }
    
    head = rev;    
}

//-----------------------------------------------------------------------------------------------------

int  MyList::size()const{
    /*Returns the number of nodes in the list.*/
    int cnt = 0;
    for(Node* curr = head; curr; curr = curr->next){
        cnt++;
    }
    return cnt;
}


void MyList::print()const{
    /*Prints the contents of the list.*/
    for(Node* curr = head; curr; curr = curr->next){
        cout << curr->value;
    }
    cout << endl;
}


int  MyList::find(char value)const{
    /*Finds the position of the first occurrence of a character value 
    in the list and returns that position. If the character is not in the list, 
    the function returns -1.*/
    int pos = 0;
    for(Node* curr = head; curr; curr = curr->next){
        if(curr->value == value){
            return pos;
        }
        else{
            pos++;
        }
    }
    return -1;
    
}


int  MyList::find(MyList& query_str)const{
    /*Finds the position of the first occurrence of MyList query_str 
    in the list and return that position. If query_str is not in the list, 
    the function returns -1.*/
    Node* curr = 0;
    int i = 0;
    int j = 0;
    //int k = 0;
    for(curr = head; curr; curr = curr->next){
        if(curr->value == query_str[j]){
            j++;
            //k++;
            if(j == query_str.size() - 1){
                return i - query_str.size() + 2; //maybe add 1
            }
        }
        else{
            j = 0;
            //k = 0;
        }
        i++;
    }
    return -1; //FIX
}

//------------------------------------------------------------------------------------

MyList& MyList::operator=(const MyList& str){
    /*Overloaded assignment operator. Assigns the contents rhs (r-value) list 
    to lhs (l-value) list, e.g. l1 = l2; Check for self-assignment.*/


    if(this != &str){
        if(head){
            delete this;
        }
        for(Node* curr = str.head; curr; curr = curr->next){
            this->push_back(curr->value);
        }
    }
    return *this;
    
}

/*
const char& MyList::operator[ ](const int pos) const{
    Overloaded [ ] operator. Reads the character located at l1[i] in list l1. 
    Program should abort via an assert statement if i is out-of-bounds.
    if(pos < 0){
        return head->value;
    }
    else if(pos >= size()){
        
    }
    Node* curr = 0;
    for(int i = 0; i < pos; i++){
        curr = curr->next;
    }
    return curr->value;
}
*/


char& MyList::operator[](const int pos){
    /*Overloaded [ ] operator. Returns writable reference to memory location 
    for list l1 at l1[i]. Program should abort via an assert statement 
    if i is out-of-bounds.*/
    assert(pos >= 0);
    assert(pos < size());
    Node* curr = head;
    for(int i = 0; i < pos; i++){
        curr = curr->next;
    }
    return curr->value;
}


MyList MyList::operator+(const MyList& str){
    /*Concatenates two lists together, i.e. l1 + l2;*/
    MyList rhs = str;
    Node* curr = 0;
    
    for(curr = str.head; curr; curr = curr->next){
        this->push_back(curr->value);
    }
    
    return *this;
}

//---------------------------------------------------------------------------------------

bool MyList::is_palindrome()const{
    /*Checks whether list object (implicit) contains a palindrome.*/
    int sz = size();
    int mid = 0;
    Node* curr = head;
    MyList l1;
    MyList l2;
    
    if(sz % 2 == 0){ //even
        mid = sz / 2;
        for(int i = 0; i < mid; i++){ //first half -> l1
            l1.push_back(curr->value);
            curr = curr->next;
        }
        for(int i = 0; i < mid; i++){ //second half -> l2
            l2.push_front(curr->value);
            curr = curr->next;
        }
    }
    else{ //odd
        mid = sz / 2;
        for(int i = 0; i < mid; i++){ //first half -> l1
            l1.push_back(curr->value);
            curr = curr->next;
        }
        
        curr = curr->next; // mid value is ignored if sz = odd
        
        for(int i = 0; i < mid; i++){ //second half -> l2
            l2.push_front(curr->value);
            curr = curr->next;
        }
    }
    
    Node* itr_1 = l1.head;
    Node* itr_2 = l2.head;
    
    for(int i = 0; i < mid; i++){
        if(itr_1->value != itr_2->value){
            return false;
        }
    }
    
    return true;
}


void MyList::merge_list(MyList A, MyList B){
    /*Merges two sorted lists A and B into implicit list object. 
    HINT: A and B are passed-by-copy.*/
    

    int i = 0;
    int j = 0;
    while(i < A.size() || j < B.size()){
        if(i < A.size() && j < B.size())
        {
            if(A[i] < B[j]){
                this->push_back(A[i]);
                i++;
            }
            else{
                this->push_back(B[j]);
                j++;
            }
        }
        else if(i < A.size()){
            this->push_back(A[i]);
            i++;
        }
        else{
            this->push_back(B[j]);
            j++;
        }
    }
    
}


bool MyList::remove_char(char c){
    /*Removes all instances of char c from implicit list object, 
    e.g. remove all commas (',')
    return true if at least one instance of char c is in the list, false otherwise.*/
    bool ok = false;
    
    Node* curr = 0;
    if(!head){
        return ok;
    }
    else if(!head->next){
        if(head->value == c){
            return true;
        }
        else{
            return false;
        }
    }
    
    for(curr = head; curr->next; curr = curr->next){
        if(curr->next->value == c){
            Node* tmp = curr->next;
            curr->next = tmp->next;
            delete tmp;
            ok = true;
        }
    }
    
    return ok;
}


char MyList::front()const{
    /*Returns the first node's value.*/
    if(head){
        return head->value;
    }
    else{
        return '!';
    }
}