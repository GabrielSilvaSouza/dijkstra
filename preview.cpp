#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include <tuple>


using namespace std;
using namespace std::chrono;

class Graph {
    int root;

    vector< tuple <int, float> > * v_w;

public:

    void graphBuilderAdjacencyVector(int numberVertex, vector< tuple <int, float> > graphLL[],  int Vertex_a, int Vertex_b);

};


void Graph::graphBuilderAdjacencyVector(int numberVertex, vector< tuple <int, float> >  graphLL[], int Vertex_a, int Vertex_b) {
            
    int weight;
    ifstream infile("grafo_1.txt");
    while(infile >> weight >> Vertex_a >> Vertex_b ) {

        graphLL[Vertex_a].push_back(make_tuple(Vertex_b,weight));

        graphLL[Vertex_b].push_back(make_tuple(Vertex_a,weight));
        
    }
    infile.close();

/*
    void what(vector< tuple <int, float> >  &graphLL) {
        for(auto& tuple: graphLL) {

            cout << get<0>(tuple) << " " << get<1>(tuple) << endl;   
        }
    }

*/

}
 

int main() {
    
    ifstream infile("grafo_1.txt");

	int numberVertex, Vertex_a, Vertex_b, edge=0;

    infile >> numberVertex;
    vector< tuple <int, float> > graphLL[numberVertex+1];

    infile.close();
    
    clock_t start, end;
    double cpu_time_used;

    Graph u;

	start = clock();
    
	u.graphBuilderAdjacencyVector(numberVertex, graphLL,  Vertex_a, Vertex_b);

    end = clock();


  
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    cout << cpu_time_used;
   
	return 0;
    
}
