#include "Quicksort.h"
#include <iostream>
#include <cstdlib> 
#include <vector>


int main(){
    vector<int> v1;
    vector<int> v2;
    
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    for(int i = 10; i > 0; i--){
        v2.push_back(i);
    }
    
    cout << "v1: ";
    for(unsigned int i = 0; i < v1.size(); i++){
        cout << v1[i] << ", ";
    }
    cout << endl;
    
    cout << "v2: "; 
    for(unsigned int i = 0; i < v2.size(); i++){
        cout << v2[i] << ", ";
    }
    cout << endl;
    
    cout << "======================" << endl;
    //result = quicksort(v, pivot)
    string pivot = "median_three";
    v1 = quicksort(v1, pivot);
    v2 = quicksort(v2, pivot);
    
    cout << "v1: ";
    for(unsigned int i = 0; i < v1.size(); i++){
        cout << v1[i] << ", ";
    }
    cout << endl;
    
    cout << "v2: "; 
    for(unsigned int i = 0; i < v2.size(); i++){
        cout << v2[i] << ", ";
    }
    cout << endl;
    
    
    cout << "=================" <<endl;
    
    vector<int> v3;
    v3.push_back(39);
    v3.push_back(17);
    v3.push_back(24);
    v3.push_back(56);
    v3.push_back(5);
    v3.push_back(13);
    v3.push_back(21);
    v3.push_back(1);
    v3.push_back(4);
    v3.push_back(15);
    cout << "v3: ";
    for(unsigned int i = 0; i < v1.size(); i++){
        cout << v3[i] << ", ";
    }
    cout << endl;
    v3 = quicksort(v3, pivot);
     cout << "v3: ";
    for(unsigned int i = 0; i < v1.size(); i++){
        cout << v3[i] << ", ";
    }
    cout << endl;
}