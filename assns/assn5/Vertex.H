/*
 * cs014_20sumA
 * Vertex.H
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>
#include <vector>

using namespace std;

const int INF = 100;

class Vertex {
public:
    Vertex(){ /* implement constructor*/ 
        label = "";
        distance = INF;
    }
    ~Vertex(){}
    string label;
    int distance;
    list<int> neighbors;
    list<int> shortest; //stores dest if to_dest is shortest path
};

#endif /* VERTEX_H_ */