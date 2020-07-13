#include "Tree.h"
#include <iostream>

using namespace std;

bool Tree::is_empty(){
    if(!root){
        return true;
    }
    else{
        return false;
    }
}
Node* Tree::find_spot(const string& new_str){
    Node* leaf = root;
    if(is_empty()){//empty
        return leaf;
    }
    
    while(new_str != leaf->get_str()){
        if(new_str < leaf->get_str()){
            if(leaf->left){
                leaf = leaf->left;
            }
            else{
                return leaf;
            }
        }
        else if(new_str > leaf->get_str()){
            if(leaf->right){
                leaf = leaf->right;
            }
            else{
                return leaf;
            }
        }
    }
    return leaf;
}
void Tree::insert(const string& new_str){
    /*
    Insert an item into the binary search tree. 
    Be sure to keep the binary search tree properties. 
    When an item is first inserted into the tree the count should be set to 1.
    When adding a duplicate string (case sensitive), 
    rather than adding another node, the count variable should 
    just be incremented.
    */
    
    if(is_empty()){ //empty
        Node* newNode = new Node(new_str);
        root = newNode;
        return;
    }
    
    Node* leaf = find_spot(new_str);
    if(new_str == leaf->get_str()){
        leaf->set_cnt(leaf->get_cnt() + 1);
        return;
    }
    else{
        Node* newNode = new Node(new_str);
        if(new_str < leaf->get_str()){
            leaf->left = newNode;
        }
        else{ //new_str > leaf->str
            leaf->right = newNode;
        }
    }
}


bool Tree::search(const string& search_str){
    /*Search for a string in the binary search tree. 
    
    It should return true if the string is in the tree, and false otherwise
    */
    
    if(is_empty()){ //empty
        return false;
    }
    Node* find = find_spot(search_str);
    if(search_str == find->get_str()){
        return true;
    }
    else{
        return false;
    }
}


void Tree::inOrder( ){
    inOrder(root);
}

void Tree::inOrder(Node* node){
    if(!node){
        return;
    }
    inOrder(node->left);
    cout << node->get_str() << endl;
    inOrder(node->right);
}


void Tree::postOrder( ){
    postOrder(root);
}
void Tree::postOrder(Node* node){
    if(!node){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->get_str() << endl;
}



void Tree::preOrder( ){
    preOrder(root);
}
void Tree::preOrder(Node* node){
    if(!node){
        return;
    }
    cout << node->get_str() << endl;
    preOrder(node->left);
    preOrder(node->right);
}


Node* Tree::find_largest(){
    Node* node = root;
    while(node->right){
        node = node->right;
    }
    return node;
}
string Tree::largest( ){
    /*Find and return the largest value in the tree. 
    Return an empty string if the tree is empty.*/
    string large = "";
    if(is_empty()){
        return large;
    }
    large = find_largest()->get_str();
    return large;
}

Node* Tree::find_smallest(){
    Node* node = root;
    while(node->left){
        node = node->left;
    }
    return node;
}
string Tree::smallest( ){
    /*Find and return the smallest value in the tree. 
    Return an empty string if the tree is empty.*/
    string small = "";
    if(is_empty()){
        return small;
    }
    small = find_smallest()->get_str();
    return small;
}

int Tree::rec_height(Node* node){
    if(!node->left && !node->right){ // base case (leaf)
        return 0;
    }
    int l = rec_height(node->left);
    int r = rec_height(node->right);
    if(l > r){
        return l + 1;
    }
    else{
        return r + 1;
    }
}
int Tree::height( const string & h_str){
    /*Compute and return the height of a particular string in the tree. 
    The height of a leaf node is 0 (count the number of edges on the longest path). 
    Return -1 if the string does not exist.*/
    if(!search(h_str)){
        return -1;
    }
    Node* node = find_spot(h_str);
    return rec_height(node);
}

/*
void Tree::remove( const string & ){
    
}
*/