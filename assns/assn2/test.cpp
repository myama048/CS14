#include <cstdlib>
#include <iostream>
#include <string>
#include "WordLadder.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
  if (argc != 4) {
    cerr << "Usage error, expected: ./a.out words*.txt start_word end_word\n";
    exit(1);
  }
  
  string dict_file = argv[1];
  string s2 = argv[2];
  string s3 = argv[3];
  
  
  WordLadder w(dict_file);
  /*
  if(w.offByOne(s2, s3)){
      cout << "it is off by one" << endl;
  }
  else{
      cout << "NOOOO" << endl;
  }
  */
  
  //w.printDictionary();
  /*
  stack<string> s;
  s.push("aaa");
  s.push("bbb");
  s.push("ccc");
  w.outputLadder(s, "aaa");
  */
  
  
  w.outputLadder(s2, s3);
  
  
  return 0;
}