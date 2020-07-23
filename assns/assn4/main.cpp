// main.cpp
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <list>

using namespace std;

// Display function declarations
void Display(list<int>&);        // displays std::list to std::out
void Display(int a[], int size); // displays array to std::out

// Sorting function declarations
void MergeSort(list<int>& S);                       // MergeSort for list
list<int>& Merge(list<int>& C, list<int>& A, list<int>& B); // Merge for list
void MergeSort(int numbers[], int i, int k);        // MergeSort for array
void Merge(int numbers[], int i, int j, int k);       // Merge for array
void InsertionSort(int numbers[], int numbersSize); // InsertionSort for array
void InsertionSort(list<int>& S);                       // InsertionSort for list

// IMPLEMENT YOUR SOLUTION BELOW MAIN FUNCTION

int main() {
  int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
  const int NUMBERS_SIZE = 8;
  const int LARGE_N = 1000;

  cout << "ARRAY:\n";
  cout << "UNSORTED: "; 
  Display(numbers, NUMBERS_SIZE);
cout << "aaa" << endl;
  list<int> seq;   
  for(int i = 0; i < NUMBERS_SIZE; i++)
    seq.push_back(numbers[i]);
//cout << "bbb" << endl;
  cout << "LIST:\n";
  cout << "UNSORTED: ";
  Display(seq);
// << "ccc" << endl;
  MergeSort(numbers, 0, NUMBERS_SIZE - 1);
  cout << "ARRAY:\n";
  cout << "SORTED: ";
  Display(numbers, NUMBERS_SIZE);
//cout << "ddd" << endl;
  MergeSort(seq);
  cout << "LIST:\n";
  cout << "SORTED: ";
  Display(seq);
cout << "eee" << endl;
  srand((unsigned)time(0));   // seed random number generator

  int* a = NULL;              // Pointer to int, initialize to OxO
  a = new int[LARGE_N];       // Allocate NUMBERS_SIZE ints and save ptr in a.
  list<int> seq2;             // list seq2
  for(int i = 0; i < LARGE_N; i++) {
    a[i] = (rand() % (LARGE_N*LARGE_N)) + 1; // insert into array
    seq2.push_back(a[i]);     // insert into list 
  }
cout << "fff" << endl;
  cout << "Array:\n"; 
  cout << "UNSORTED:";
  Display(a, NUMBERS_SIZE);
cout << "ggg" << endl;
  cout << "LIST:\n";
  cout << "UNSORTED: ";
  Display(seq2);

  MergeSort(a, 0, NUMBERS_SIZE - 1);
 cout << "hhh" << endl;
  cout << "Array:\n"; 
  cout << "SORTED: ";
  Display(a, NUMBERS_SIZE);
cout << "iii" << endl;
  MergeSort(seq2);
  cout << "LIST:\n";
  cout << "SORTED: ";
  Display(seq2);
cout << "jjj" << endl;
  numbers[0] = 20;
  numbers[1] = 10;
  numbers[2] = 79; 
  numbers[3] = 2; 
  numbers[4] = 200;
  numbers[5] = 50;
  numbers[6] = -50;
  numbers[7] = -51;

  cout << "UNSORTED: ";
  for(int i = 0; i < NUMBERS_SIZE; ++i) {
   cout << numbers[i] << " ";
  }
  cout << endl;

  InsertionSort(numbers, NUMBERS_SIZE);
cout << "ggggggggggggggggggggggggggg" <<endl;
  cout << "SORTED: ";
  for(int i = 0; i < NUMBERS_SIZE; ++i) {
   cout << numbers[i] << " ";
  }
  cout << endl;
  
  int gg = 15;
  int ggg[] = {2,5,235,63,62,23,72,4,6,20,50,12,14,1,0};
  
  for(int i = 0; i < gg; i++){
    cout << ggg[i] << " ";
  }
  cout <<"ok" << endl;
  InsertionSort(ggg, gg);
  for(int i = 0; i < gg; i++){
    cout << ggg[i] << " ";
  }
  cout << endl;
  
  return 0;
}

void Display(int a[], int size) {
 for(int i = 0; i < size; ++i) 
   cout << a[i] << " ";
 cout << endl;
}

void Display(list<int>& S) {
  for(list<int>::iterator it = S.begin(); it != S.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

// IMPLEMENT YOUR SOLUTION HERE!!

void MergeSort(list<int>& S){  // MergeSort for list
    if(S.size() > 1){
      list<int> S1;
      list<int> S2;
      
      unsigned int i = 0;   //partition
      for(list<int>::iterator itr = S.begin(); itr != S.end(); itr++){
        if(i < S.size()/2){
          S1.push_back(*itr);
        }
        else{
          S2.push_back(*itr);
        }
        i++;
      }
      
      MergeSort(S1);
      MergeSort(S2);
      //cout << "ok" << endl;
      S = Merge(S,S1,S2);
    }
}                      
list<int>& Merge(list<int>& C, list<int>& A, list<int>& B){ // Merge for list
    C.clear();
    while(!A.empty() && !B.empty()){
      if(A.front() < B.front()){
        C.push_back(A.front());
        A.pop_front();
      }
      else{
        C.push_back(B.front());
        B.pop_front();
      }
    }
    while(!A.empty()){
      C.push_back(A.front());
      A.pop_front();
    }
    while(!B.empty()){
      C.push_back(B.front());
      B.pop_front();
    }
    return C;
}


void MergeSort(int numbers[], int i, int k){ // MergeSort for array i = first indx, k = last indx
    if(i < k){
      int q = (i + k)/2; // q is mid
      MergeSort(numbers, i, q);
      MergeSort(numbers, q+1, k);
      Merge(numbers, i,q,k);
    }
}       
void Merge(int numbers[], int p, int q, int r){ // Merge for array
  int tmp[100];
  int i = p;
  int j = q + 1;
  int k = 0;
  
  while(i <= q && j <= r){
    if(numbers[i] <= numbers[j]){
      tmp[k] = numbers[i];
      i++;
    }
    else{
      tmp[k] = numbers[j];
      j++;
    }
    k++;
  }
  while(i <= q){
    tmp[k] = numbers[i];
    k++;
    i++;
  }
  while(j <= r){
    tmp[k] = numbers[j];
    k++;
    j++;
  }
  
  for(i = p; i <= r; i++){
    numbers[i] = tmp[i - p];
  }
}     

void swap(int numbers[], int i, int j){
  int cpy = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = cpy;
}
void InsertionSort(int numbers[], int numbersSize){// InsertionSort for array
    for(int i = 1; i < numbersSize; i++){
      int j = 0;
      while(j < i && numbers[j] < numbers[i]){
        j++;
      }
      if(j != i){
        while(j != i){
          if(numbers[i] < numbers[j])
            swap(numbers, i, j); //swap num[i] and num[2]
          j++;
        }
      }
        
    }
} 



void InsertionSort(list<int>& S){ // InsertionSort for list
    list<int> l;
    l.push_back(S.front());
    S.pop_front();
    
    for(list<int>::iterator itr = S.begin(); itr != S.end(); itr++){
      list<int>::iterator l_it = l.begin();
      while(*l_it < *itr){
        l_it++;
      }
      l.insert(l_it, *itr);
    }
    
    S = l;
}                       