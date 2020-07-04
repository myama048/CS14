/**
 * cs014_sum20A
 * Sample main with exceptions
 * Stack template
 * main.cc
 * RR
 */

#include <iostream>
#include <vector>
#include "stack.h"
#include <stdexcept>

using namespace std;

int main() {

  string name = "Neo";
  Stack<string> s1; // empty Stack of strings

  try {   // try block
    // ternary operator, displays warning if Stack instance is empty
    s1.is_empty() ? cout << "\nNon-Exception check: Empty stack\n" : cout  
      << "Non-Exception check: Non-empty Stack<string>\n";

    s1.push(name);
    s1.push(name);
    s1.push(name);
    s1.push(name);
    s1.push(name);
   // s1.push(name);  // test 1: Raises Stack overflow_error exception, uncomment this line in try block to test

  } catch(overflow_error& e) { // catch block
    cerr << "Overflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  try {
	  cout << s1.top() << endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }
  
  try {
    //s1.top(); // test 2: Raises underflow exception, uncomment this line only in try block to test
    s1.push("Trinity"); 
    s1.pop();
    //s1.pop(); // test 3: Raises underflow exception, uncomment this line only in try block to test
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }
  
  Stack<int> s2; // empty Stack of ints
  try {
    // ternary operator, displays warning if Stack instance is empty
    s2.is_empty() ? cout << "\nNon-Exception check: Empty stack\n" : cout  
      << "Non-Exception check: Non-empty Stack<int>\n";
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    //s2.push(6);  // test 4: Raises Stack overflow_error exception, uncomment this line in try block to test

  } catch(overflow_error& e) {
    cerr << "Overflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Whoops! Catch-all block, Stack<int>, terminating program.\n";
  }
  
  try {
	  cout << s2.top() << endl;
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  try {
    //s2.top(); // test 5: Raises underflow exception, uncomment this line only in try block to test
    s2.push(77); 
    s2.pop();
    //s.pop(); // test 6: Raises underflow exception, uncomment this line only in try block to test
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, Stack<int>, terminating program.\n";
  }
  
  /* This code demonstrates that the std::vector m,ember function at()
   * automatically checks whether n is within the bounds of valid elements
   * in the vector, throwing an out_of_range exception if the argument n in
   * v.at(n) is not in range 0 to v.size()-1.
   */
  try {
    // Raises out_of_range exception, uncomment next two lines in try block to test
    // vector<int> myvector(10);
    // cout << myvector.at(20); // vector::at throws an out-of-range
  } catch(out_of_range& e) { // catch block
    cerr << "Out of range error: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  cout << "\nThe program flow continues...\n";
  cout << "The \"return 0;\" statement will cause the program to exit.\n";

  return 0;
}

