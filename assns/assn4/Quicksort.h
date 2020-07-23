#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void quicksort_rand(vector<T>& v, int i, int k);
template<typename T>
void quicksort_med(vector<T>& v, int i, int k);
template<typename T>
int partition(vector<T>& v, int i, int k, string& p);

template<typename T>
vector<T>& quicksort(vector<T>& v, const string& pivot) {
    int i = 0;
    int k = v.size() - 1;
    if(pivot == "random"){
        quicksort_rand(v, i, k);
    }
    else if(pivot == "median_three"){
        quicksort_med(v, i, k);
    }
    return v;
}

template<typename T>
void quicksort_rand(vector<T>& v, int i, int k){
    if(i >= k){
        return;
    }    
    string str = "random";
    int j = partition(v,i,k,str);
    quicksort_rand(v,i,j);
    quicksort_rand(v,j+1,k);
}

template<typename T>
void quicksort_med(vector<T>& v, int i, int k){
    if(i >= k){
        return;
    }
    string str = "median_three";
    int j = partition(v,i,k,str);
    quicksort_med(v,i,j);
    quicksort_med(v,j+1,k);
}

template<typename T>
int partition(vector<T>& v, int i, int k, string& p){
    int l = i;
    int h = k;
    bool done = false;
    T pivot = 0;
    if(p == "random"){
        pivot = v[rand() % v.size()];
    }
    else if(p == "median_three"){
        T p1 = v[rand() % v.size()];
        T p2 = v[rand() % v.size()];
        T p3 = v[rand() % v.size()];
        
        if(p1 < p2){
            if(p2 < p3){
                pivot = p2;
            }
            else{
                pivot = p3;
            }
        }
        else{
            if(p1 < p3){
                pivot = p1;
            }
            else{
                pivot = p3;
            }
        }
    }
    
    while(!done){
        while(v[l] < pivot){
            l++;
        }
        while(pivot < v[h]){
            h--;
        }
        
        if(l >= h){
            done = true;
        }
        else{
            T temp = v[l];
            v[l] = v[h];
            v[h] = temp;
            ++l;
            --h;
        }
    }
    return h;
}