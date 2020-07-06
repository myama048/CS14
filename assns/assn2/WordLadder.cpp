#include<iostream>
#include "WordLadder.h"
using namespace std;

WordLadder::WordLadder(){
    
}


WordLadder::WordLadder(const string& listFile){
    //Constructor that passes in the name of the dictionary file
    // --> list<string> dict;
    ifstream myFile;
    myFile.open(listFile);
    if(!myFile.is_open()){
        cerr << "File: " << listFile << " can not be opened" << endl;
        return;
    }
    else{
        string str;
        while(myFile >> str){
            dict.push_back(str);
        }   
        myFile.close();
    }
}


WordLadder::~WordLadder(){
    dict.clear();
    //delete &wl;
}


void WordLadder::outputLadder(const string& start, const string& end){
    //passes in the start and end words and outputs to standard output the word ladder.
    //cout << "a" ;
    stack<string> first;
    //cout << "b";
    first.push(start);
    //cout << 'd';
    wl.push(first);
    cout << "aaa " << endl;
    /*
    stack<string> cpy = first;
    while(!cpy.empty()){
        cout << cpy.top();
        cpy.pop();
    }
    */
    cout << "YYY";
    while(!wl.empty()){
        //cout << "bbb " ;
        for(auto itr = dict.begin(); itr != dict.end(); itr++){
            cout << "1 " ;
            if(offByOne(*itr, wl.front().top())){ //find offByOne word from dict
                cout << "2 ";
                if(*itr == end){ // find the end word
                    cout << "A word ladder found" << endl;
                    outputLadder(wl.front(), start); 
                    return;
                }
                else{
                    cout << "4 ";
                    stack<string> tmp = wl.front();
                    tmp.push(*itr);
                    wl.push(tmp);
                }
                dict.remove(*itr); // remove the word from dict
            }
            else{
                // do nothing
                cout << "5 ";
            }
        }
        wl.pop();
    }
    cout <<"No Ladder found!" << endl;
}


void WordLadder::outputLadder(stack<string>& s, const string& start){
    list<string> l;
    stack<string> cpy = s;
    
    while(!cpy.empty()){
        l.push_front(cpy.top());
        cpy.pop();
    }
    
    for(auto it = l.begin(); it != l.end(); it++){
        cout << *it << ' ';
    }
    //cout << start;
    if(start == ""){} // why is start neccessary?
    cout << endl;
}


void WordLadder::printDictionary(){
    for(auto itr = dict.begin(); itr != dict.end(); itr++){
        cout << *itr << endl;
    }
    cout << endl;
}


bool WordLadder::offByOne(const string& s1, const string& s2){
    int cnt = 0;
    if(s1.size() != s2.size()){
        return false;
    }
    else{
        for(unsigned int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                cnt++;
            }
        }
    }
    return (cnt == 1);
}
