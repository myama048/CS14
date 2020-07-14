/**
 * cs014_sum20A
 * lab4-5
 * main.cc
 * RR
 */

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  
  if(argc != 2) {
    cerr << "Usage error: expected <executable> <mode>" << endl;
    exit(1);
  }
  
  string cmd = "";
  int key = -1;
  BST t;
  string mode = argv[1];
  
  // ofstream you will use to write to file output.dot
  // currently an empty output.dot gets written into pwd
  ofstream ofs("output.dot");
  if(!ofs) {
    cout << "output.dot could not be opened." << endl;
    exit(1);
  }
  
  for(;;) {
    cin >> cmd;
    if(cmd == "insert") {
      cin >> key;
      t.insert(key);
    }
    else if(cmd == "remove") {
      cin >> key;
      t.remove(key);
    }
    else if(cmd == "dotty") {
      
      
      cout << "mode = " << mode << endl; //remove once mode used in program
      // implement code here that will produce the correct dot file
      // based on the user's preference (mode), i.e., preorder, postorder,
      // inorder, node height
      if(mode == "preorder") t.preorder();
      else if(mode == "postorder") t.postorder();
      else if(mode == "inorder") t.inorder();
      else if(mode == "height") t.height();
      
    }
    else if(cmd == "display") t.display();
    else if(cmd == "end") break;
    else if(cmd == "preorder") t.preorder();
    else if(cmd == "postorder") t.postorder();
    else if(cmd == "inorder") t.inorder();
    else if(cmd == "height") t.height();
    else
      cout << cmd << ", not found, try again." << endl;
  }
  // close ofstream
  cout << "Good bye!" << endl;
  return 0;
}
