/*
 * cs014_20sumA
 * Vertex.H
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>

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
};

#endif /* VERTEX_H_ */