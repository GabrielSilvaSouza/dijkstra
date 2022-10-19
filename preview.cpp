#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;

class Graph {
    int root;

public:
    
    bool graphBuilderAdjacencyVector( int numberVertex, vector<bool> graphLL[],  int Vertex_a, int Vertex_b);

    //void Dijkstra(int r);

};


bool Graph::graphBuilderAdjacencyVector(int numberVertex, vector<bool>  graphLL[], int Vertex_a, int Vertex_b) {
            
    int weight;
    tuple <int, int> v_w;
    ifstream infile("grafo_1.txt");
    while(infile >> weight >> Vertex_a >> Vertex_b ) {
        v_w = make_tuple(Vertex_b,weight);
        graphLL[Vertex_a].push_back(Vertex_b);
        graphLL[Vertex_b].push_back(Vertex_a);
        
        //graphLL[Vertex_b].push_back(std::make_pair(Vertex_a, weight));
    }
    infile.close();
    
    return graphLL;
    
}
 

int main() {

    //printf("checked");
    //double v = 2.9;
    //printf("%f",v);
    
    
    ifstream infile("grafo_1.txt");
	int numberVertex,Vertex_a, Vertex_b, edge=0;
    infile >> numberVertex;
    vector<bool> graphLL[numberVertex+1];
    infile.close();
    

    clock_t start, end;
    double cpu_time_used;

    Graph u;

	start = clock();
    
	u.graphBuilderAdjacencyVector( numberVertex, graphLL,  Vertex_a, Vertex_b);

    end = clock();

    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    cout << cpu_time_used;

	

	return 0;
    
}
