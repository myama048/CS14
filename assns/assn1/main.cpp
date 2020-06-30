#include <iostream>
#include <vector>
#include <string>
#include "MyList.h"

using namespace std;

int main() {

  char c = 'a';
  MyList l1;

  cout << "push_back z: " ;
  l1.push_back('z');
  l1.print();

  l1.pop_back();
  cout << "pop_back z: " ;
  l1.print();

  cout << "push_front 0 0 z 0 z: " ;
  l1.push_front('0');
  l1.push_front('0');
  l1.push_front('z');
  l1.push_front('0');
  l1.push_front('z');
  //cout << "hello"<<endl;
  l1.print();
  //cout << "hellllo" << endl;
  //cout << l1.size() << endl;
  int loc_size = l1.size();
  cout << "array style print: ";
  //cout << "!!!" << endl;
  //cout << l1[0] << l1[1] << l1[2] << l1[3] << endl;
  //cout << "!!!!" << endl;
  //cout << loc_size << endl;
  for(int i = 0; i < loc_size; i++){
    //cout << "9";
    cout << l1[i] << " ";
    //cout << "10";
  }
  cout << endl;

  cout << "insert_at_pos a 0 on left and right of middle z: " ;
  l1.insert_at_pos(2, '0');
  l1.insert_at_pos(5, '0');
  l1.print();

  cout << "push_back letters f-j: ";
  for(int i = 0; i < 10; i++)
    l1.push_back(c+i);
  l1.print();

  cout << "pop_front z z: ";
  for(int i = 0; i < 2; i++)
    l1.pop_front();
  l1.print();

  cout << "pop_back f-j: ";
  for(int i = 0; i < 5; i++)
    l1.pop_back();
  l1.print();

  cout << "reverse odd sized list: ";
  l1.reverse();
  l1.print();

  cout << "push_front f: ";
  l1.push_front('f');
  l1.print();

  cout << "reverse even sized list: ";
  l1.reverse();
  l1.print();

  // make some copies for later use
  cout << "Construct new lists l2,l3,l4:\n";
  cout << "MyList l4(l1);\nMyList l3 = l4;\nMyList l2(l3);" << endl;
  MyList l4(l1);
  MyList l3 = l4;
  MyList l2(l3);

  // test pop_back
  cout << "pop_back entire list, l1: ";
  loc_size = l1.size();

  for(int i = 0; i < loc_size; i++)
    l1.pop_back();
  l1.print();

  // test reverse
  cout << "reverse empty list, l1: ";
  l1.reverse();
  l1.print();

  cout << "pop_back entire list but one item, l2: ";
  loc_size = l2.size();

  for(int i = 0; i < loc_size-1; i++)
    l2.pop_back();
  l2.print();;

  cout << "reverse one item list, l2: ";
  l2.reverse();
  l2.print();

  cout << "pop_back entire list but two items, l3: ";
  loc_size = l3.size();

  for(int i = 0; i < loc_size-2; i++)
    l3.pop_back();
  l3.print();

  cout << "reverse two item list, l3: ";
  l3.reverse();
  l3.print();

  cout << "list l4: ";
  l4.print();

  cout << "list l4 + l3: ";
  l4 + l3; 
  l4.print();

  cout << "list l4 + l2: ";
  l4 + l2; 
  l4.print();

  cout << "list l4 + l1: ";
  l4 + l1; 
  l4.print();
  
  MyList pp;
  pp.push_back(1);
  pp.push_back(2);
  pp.push_back(1);
  
  
  if(!pp.is_palindrome()){
    cout << "l4 is not palindrome" << endl;
  }else{
    cout << "it is palindrome" << endl;
  }
  
  l3.print();
  MyList tst = l3;
  tst.print();
  tst.push_back('3');
  tst.print();
  l3.print();
  
  //MyList pd = "AmoRe- RomA";
  MyList pd;
  pd.push_back('A');
  pd.push_back('m');
  pd.push_back('o');
  pd.push_back('R');
  pd.push_back('e');
  pd.push_back('-');
  pd.push_back(' ');
  pd.push_back('R');
  pd.push_back('o');
  pd.push_back('m');
  pd.push_back('A');
  pd.print();
  cout << pd.size() << endl;
  if(pd.is_palindrome()){
    cout << "yes" << endl;
  }
  else{
    cout << "no" << endl;
  }

  cout << "Good Bye!" << endl;
  
  string str = "Innovation!";
  cout << '0' << endl;
  MyList cc("Innovation?");
  cout << "a" << endl;
  MyList dd(str);
  cout << '1' << endl;
  dd.print();
  cout << '2' << endl;
  
  return 0;
}