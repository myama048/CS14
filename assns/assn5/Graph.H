/*
 * cs014_20sumA
 * Graph.H
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Vertex.H"

using namespace std;

class Graph {
public:
    Graph(){}
    Graph(ifstream& ifs){ /* implement overloaded constructor */ 
        build_graph(ifs);
    }
    ~Graph(){
        vertices.clear();
    }
    void build_graph(ifstream& ifs){ /* implement build_graph */ 
        int numV;
        int numE;
        string str;
        
        if(ifs.is_open()){
            ifs >> numV;
            ifs >> numE;
            
            for(int i = 0; i < numV; i++){ 
                ifs >> str;
                Vertex v;
                v.label = str;
                vertices.push_back(v);
            }
            
            string source;
            string dest;
            for(int i = 0; i < numE; i++){
                ifs >> source;
                ifs >> dest;
                int s_pos = 0;
                int d_pos = 0;
                while(vertices[s_pos].label != source){
                    s_pos++;
                }
                while(vertices[d_pos].label != dest){
                    d_pos++;
                }
                
                vertices[s_pos].neighbors.push_back(d_pos); // add new dest as soucre's neighbor
            }
        }
    }
    void output_graph(){ /* implement output_graph */ 
        ofstream myfile;
        myfile.open("graph.dot");
        myfile.clear();
        myfile << "digraph G {\n" << endl;
        for(unsigned int i = 0; i < vertices.size(); i++){
            myfile << "    " << vertices[i].label << ";" << endl;
        }
        myfile << endl;
        for(unsigned int i = 0; i < vertices.size(); i++){
            for(list<int>::iterator it = vertices[i].neighbors.begin(); it != vertices[i].neighbors.end(); it++){
                myfile << "    " << vertices[i].label << "->" << vertices[*it].label;
                bool find = false;
                for(list<int>::iterator s_it = vertices[i].shortest.begin(); s_it != vertices[i].shortest.end(); s_it++){
                    if(vertices[*it].label == vertices[*s_it].label){
                        myfile << " [style=bold, color = blue]";
                        find = true;
                    }
                }
                if(!find){
                    myfile << " [style=dotted]";
                }
                myfile << endl;
            }
        }
        
        myfile << "}";
        myfile.close();
    }
    void bfs(){ /* implement bfs */ 
        queue<Vertex> q;
        vertices.front().distance = 0;
        q.push(vertices.front());
        
        while(!q.empty()){
            for(list<int>::iterator it = q.front().neighbors.begin(); it != q.front().neighbors.end(); it++){
                if(vertices[*it].distance == 100){
                    //--extra credit--
                    int pos = 0;
                    for(pos = 0; q.front().label != vertices[pos].label;pos++){}
                    vertices[pos].shortest.push_back(*it);
                    //----------------
                    vertices[*it].distance = q.front().distance + 1;
                    q.push(vertices[*it]);
                }
            }
            q.pop();
        }
    }
private:
    vector<Vertex> vertices;
};

#endif /* GRAPH_H_ */