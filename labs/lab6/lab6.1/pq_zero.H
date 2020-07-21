#include <vector>

#include <map>

#include <limits>

using namespace std;

template < typename Item >
  class pq_zero {
    vector < Item > heap;
    typedef int indx;
    map < Item, indx > index;
    map < Item, float > priority;
    
    void percolate_up(indx i) {
      if(i && heap.at(parent(i)) > heap[i]){
        swap(heap[i], heap[parent(i)]);
        percolate_up(parent(i));
      }
    }

    void percolate_down(indx i) {
      int left = i*2 + 1;
      int right = i*2 + 2;
      int smallest = i;
      
      if(left < size() && priority[heap[left]] < priority[heap[smallest]])
        smallest = left;
    
      if(right < size() && priority[heap[right]] < priority[heap[smallest]])
        smallest = right;
      
      if(smallest != i) {
        swap(heap[i], heap[smallest]);
        percolate_down(smallest);
      }
    }
    
    //------------------------------------------------------------
    // This is just us helping you out
    // Use if needed
    // Add/delete if needed
    
    indx first(){
      return index.at(front());
    }
    indx last(){
      return index.at(heap.at(heap.size()-1));
      //size();  
    }
    indx parent( indx i ){
      return (i-1)/2;
    }
    indx left( indx i ){
      return (i*2 + 1);
    }
    indx right( indx i ){
      return (i*2 + 2);
    }  
    bool is_leaf( indx i ){
      if(left(i) > heap.size() && right(i) > heap.size()){
        return true;
      }
      else{
        return false;
      }
    }
    bool exists( indx i ){
      return (i < heap.size());
    }
    bool precedes( indx i, indx j );
    
    //------------------------------------------------------------

  public:
    int size() const{
      return heap.size();
    }
    
    bool empty() const{
      return (heap.size() == 0);
    }
    
    const Item & front() const{
      if (empty()) {
        exit(1);
      }
      
      return heap.at(0);
    }
    
    void pop(){
      if (empty()) {
        exit(1);
      }
      
      heap[0] = heap[last()];
      heap.pop_back();
      percolate_down(0);
    }
    
    void push(const Item & w, float prio){
      index[w] = heap.size();
      priority[w] = prio;
      heap.push_back(w);
      percolate_up(index[w]);     //if neccessary
      percolate_down(index[w]);   //if neccessary
    }
  };