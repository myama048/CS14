#include "Quicksort.h"
#include <iostream>
#include <cstdlib> 
#include <vector>

#define SEQ_SIZE 100
#define ASSERT(condition) { if(condition) { cerr << "Assertion passed: " << #condition << endl; } else { cerr << "Assertion failed: " << #condition << endl; } }

using namespace std;


template<typename T>
void Display(std::vector<T> ;<int>& S) {
  for(vector<int>::iterator it = S.begin(); it != S.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

bool QuickSortRandom() {
    vector<int> seq;
    
    for (int i = SEQ_SIZE; i > 0; i--) {
        seq.push_back((rand() % SEQ_SIZE) + 1);
    }
    
    // cout << "Unsorted list: " << endl;
    // Display(seq);
    
    quicksort(seq, "random");
    
    // cout << "Sorted list: " << endl;
    // Display(seq);
    
    vector<int>::iterator iter = seq.begin();
    int key = *iter;
    
    for(iter++; iter != seq.end(); iter++)
    {
        if(!(key <= *iter))
            return false;
        else
            key = *iter;
    }
    
    return true;
}

bool QuickSortMedianThree() {
    vector<int> seq;
    
    for (int i = SEQ_SIZE; i > 0; i--) {
        seq.push_back((rand() % SEQ_SIZE) + 1);
    }
    
    // cout << "Unsorted list: " << endl;
    // Display(seq);
    
    QuickSort(seq, "median_three");
    
    // cout << "Sorted list: " << endl;
    // Display(seq);
    
    vector<int>::iterator iter = seq.begin();
    int key = *iter;
    
    for(iter++; iter != seq.end(); iter++)
    {
        if(!(key <= *iter))
            return false;
        else
            key = *iter;
    }
    
    return true;
}

int main() {
    ASSERT(QuickSortRandom());
    ASSERT(QuickSortMedianThree());
}