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

static int al = 0;
class BST {

private:
  
  struct BinaryNode {

    int value;
    BinaryNode* left;
    BinaryNode* right;
    char alph;
    int depth;
    int height;
    int inorder_num;
    int preorder_num;
    int postorder_num;
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	      t = new BinaryNode(v);
	      t->alph = 'a' + al++;//
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
  
  void inorder() {
    ofstream myfile;
    myfile.open("inorder.dot");
    myfile.clear();
    myfile << "digraph G {" << endl;
    inorder(root, myfile); 
    myfile << endl;
    inorder2(root, myfile);
    myfile << "}" << endl;
    myfile.close();
    cout << "inorder" << endl;
    
    
    ofstream myfile2;
    myfile2.open("output.dot");
    myfile2.clear();
    myfile2 << "digraph G {" << endl;
    myfile2 << "//inorder" << endl;
    inorder(root, myfile2); 
    myfile2 << endl;
    inorder2(root, myfile2);
    myfile2 << "}" << endl;
    
    myfile2 << endl;
    
    myfile2 << "digraph G{" << endl;
    myfile2 << "//preorder" << endl;
    preorder(root, myfile2); 
    myfile2 << endl;
    preorder2(root, myfile2);
    myfile2 << "}" << endl;
    
    myfile2 << endl;
    
    myfile2 << "digraph G{" << endl;
    myfile2 << "//postorder" << endl;
    postorder(root, myfile2);
    myfile2 << endl;
    postorder2(root, myfile2);
    myfile2 << "}" << endl;
    
    myfile2 << endl;
    
    myfile2 << "digraph G{" << endl;
    myfile2 << "//height" << endl;
    height(root, myfile2); 
    myfile2 << endl;
    height2(root, myfile2);
    myfile2 << "}" << endl;
    
    myfile2.close();
    
  }
  void inorder(BinaryNode* t, ofstream& of){
    //static char alph = 'a';
    static int in_num = 1;
    if(t == NULL) return;
    inorder(t->left, of);
    t->inorder_num = in_num++;
    of << t->alph << ' ' << "[color = red, peripheries = 2, style = filled, label=\"key=" <<
    t->value << ", in=" << t->inorder_num << "\"];"<< endl;
    //alph++;
    inorder(t->right, of);
  }
  void inorder2(BinaryNode* t, ofstream& of){
    if(t == NULL) return;
    inorder2(t->left, of);
    if(t->left){
      of << t->alph << " -> " << t->left->alph << ";" << endl;
    }
    if(t->right){
      of << t->alph << " -> " << t->right->alph << ";" << endl;
    }
    inorder2(t->right, of);
  }
  
  void preorder(){
    ofstream myfile;
    myfile.open("preorder.dot");
    myfile.clear();
    myfile << "digraph G{" << endl;
    preorder(root, myfile); 
    myfile << endl;
    preorder2(root, myfile);
    myfile << "}" << endl;
    myfile.close();
    cout << "preorder" << endl;
    
  }
  void preorder(BinaryNode* t, ofstream& of){
    //static char alph = 'a';
    static int pre_num = 1;
    if(t == NULL) return;
    t->preorder_num = pre_num++;
    of << t->alph << ' ' << "[color = orange, peripheries = 2, style = filled, label=\"key=" <<
    t->value << ", pre=" << t->preorder_num << "\"];"<< endl;
    //alph++;
    preorder(t->left, of);
    preorder(t->right, of);
  }
  void preorder2(BinaryNode* t, ofstream& of){
    if(t == NULL) return;
    if(t->left){
      of << t->alph << " -> " << t->left->alph << ";" << endl;
    }
    if(t->right){
      of << t->alph << " -> " << t->right->alph << ";" << endl;
    }
    preorder2(t->left, of);
    preorder2(t->right, of);
  }
  

  void postorder(){
    ofstream myfile;
    myfile.open("postorder.dot");
    myfile.clear();
    myfile << "digraph G{" << endl;
    postorder(root, myfile);
    myfile << endl;
    postorder2(root, myfile);
    myfile << "}" << endl;
    myfile.close();
    cout << "postorder" << endl;
  }
  void postorder(BinaryNode* t, ofstream& of){
    if(t == NULL) return;
    //static char alph = 'a';
    static int post_num = 1;
    postorder(t->left, of);
    postorder(t->right, of);
    t->postorder_num = post_num++;
    of << t->alph << ' ' << "[color = red, peripheries = 2, style = filled, label=\"key=" <<
    t->value << ", in=" << t->postorder_num << "\"];"<< endl;
    //alph++;
  }
  void postorder2(BinaryNode* t, ofstream& of){
    if(t == NULL) return;
    postorder2(t->left, of);
    postorder2(t->right, of);
    if(t->left){
      of << t->alph << " -> " << t->left->alph << ";" << endl;
    }
    if(t->right){
      of << t->alph << " -> " << t->right->alph << ";" << endl;
    }
  }
  
  void height(){
    ofstream myfile;
    myfile.open("height.dot");
    myfile.clear();
    myfile << "digraph G{" << endl;
    height(root, myfile); 
    myfile << endl;
    height2(root, myfile);
    myfile << "}" << endl;
    myfile.close();
    cout << "height" << endl;
  }
  void height(BinaryNode* t, ofstream& of){
    if(t == NULL) return;
    //static char alph = 'a';
    height(t->left, of);
    t->height = tree_height(t);
    of << t->alph << ' ' << "[color = lightblue, style = filled, label=\"key=" <<
    t->value << ", h=" << t->height - 1 << "\"];"<< endl;
    //alph++;
    height(t->right, of);
  }
  void height2(BinaryNode* t, ofstream& of){
    if(t == NULL) return;
    if(t->left){
      of << t->alph << " -> " << t->left->alph << "[color=blue];" << endl;
    }
    if(t->right){
      of << t->alph << " -> " << t->right->alph << "[color=blue];" << endl;
    }
    height2(t->left, of);
    height2(t->right, of);
  }
  
  int tree_height(BinaryNode* node) {
    if (!node)
        return 0;
    else {
        int left_height = tree_height(node->left);
        int right_height = tree_height(node->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
  
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

