#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

using namespace std;

class Tree {

private:
  Node *root;

private:
  void preOrder( Node * );
  void inOrder(Node*);
  void postOrder(Node*);

public:
  void insert( const string & );
  bool search( const string & );
  void inOrder( );
  void postOrder( );
  void preOrder( );
  string largest( );
  string smallest( );
  int height( const string & );
  //void remove( const string & );

  // Add any additional variables/functions here
  Node* find_spot(const string& new_str);
  bool is_empty();
  Node* find_largest();
  Node* find_smallest();
  
  int rec_height(Node*);

};

#endif