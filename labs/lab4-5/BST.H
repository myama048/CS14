/**
 * cs014_sum20A
 * lab4-5
 * BST.H
 * RR
 */

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class BST {

private:
  struct BinaryNode {

    int value;
    BinaryNode* left;
    BinaryNode* right;
    int depth;
    int height;
    int inorder_num;
    int preorder_num;
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	      t = new BinaryNode(v);
      }
      else if (v < t->value)
	      t->left = insert(v, t->left);
      else if (v > t->value)
	      t->right = insert(v, t->right);
      else
	      t->value = v;
      return t;
    }
    
    static BinaryNode* remove(int v, BinaryNode* t) {
      if(t) {
	      if(v < t->value)
	        t->left = remove(v, t->left);
	      else if(t->value < v)
	        t->right = remove(v, t->right);
	      else if(t->left != NULL && t->right != NULL) {
	        t->value = find_min(t->right)->value;
	        t->right = remove(t->value, t->right);
	    } else {
	       BinaryNode* oldNode = t;
	       t = (t->left != NULL) ? t->left : t->right;
	       delete oldNode;
	      }
      }
      return t;
    }
    
    static BinaryNode* find_min(BinaryNode* t) {
      if(t == NULL)
	      return NULL;
      if(t->left == NULL)
	      return t;
      return find_min(t->left);
    }

  };

public:
  BST(): root(NULL) {}
  ~BST() {}
  void insert(int v) { root = BinaryNode::insert(v, root); }
  void remove(int v) { root = BinaryNode::remove(v, root); }
  
  void inorder() {inorder(root); cout << "inorder" << endl;}
  void inorder(BinaryNode* t){
    if(t == NULL) return;
    inorder(t->left);
    cout << t->value << "," << endl;
    inorder(t->right);
  }
  
  void preorder(){preorder(root); cout << "preorder" << endl;}
  void preorder(BinaryNode* t){
    if(t == NULL) return;
    cout << t->value << "," << endl;
    preorder(t->left);
    preorder(t->right);
  }
  
  void postorder(){postorder(root); cout << "postorder" << endl;}
  void postorder(BinaryNode* t){
    if(t == NULL) return;
    postorder(t->left);
    postorder(t->right);
    cout << t->value << "," << endl;
  }
  
  //void height(){height}
  
  void display() { display(root); }
  void display( BinaryNode* t ) {
    // in-order traversal with indented display.
    static int depth = 0;
    ++depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) display(t->right);
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL )
      display(t->left);
    --depth;
  }
  private:
    BinaryNode* root;
    
  
    
  
    
};

#endif /* BST_H_ */

