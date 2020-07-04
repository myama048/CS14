#ifndef __STACK_H_
#define __STACK_H_


#define MAX_SIZE 5


#include <stdexcept>


using namespace std;


template<typename T>
class Stack {
private:
    T* container;
    int t;
public:
    Stack();
    ~Stack();
    void push(const T& x);
    T& top();
    void pop();
    bool is_empty() const;
};


template<typename T>
Stack<T>::Stack() { 
    t = -1;
    container = new T[MAX_SIZE];
}


template<typename T>
Stack<T>::~Stack () {
    delete container;
}


template<typename T>
void Stack<T>::push(const T& x){
    if(t == MAX_SIZE){
        throw overflow_error("Stack Overflow");
    }
    else{
        t++;
        container[t] = x;
    }
}


template<typename T>
T& Stack<T>::top(){
    return container[t];
}


template<typename T>
void Stack<T>::pop(){
    if(is_empty()){
        throw underflow_error("Stack Underflow");
    }
    else{
        t--;
    }
}


template<typename T>
bool Stack<T>::is_empty() const{
    return (t == -1);
}


#endif
