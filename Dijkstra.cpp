#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include <tuple>

using namespace std;

class Graph { 

    int numberVertex; 

    vector< tuple <int, float> > * graphLL;  

public:

    Graph(int n) 
    {

        ifstream infile("grafo_1.txt"); 
        int numberVertex;
        infile >> numberVertex;
        infile.close();

        //this->numberVertex = numberVertex;

        graphLL = new vector< tuple <int, float> > [numberVertex+1];
    }


    void graphBuilderAdjacencyVector(int Vertex_a, int Vertex_b) 
    {
            
        float weight;
        ifstream infile("grafo_1.txt"); 
        infile >> weight;

        while(infile >> Vertex_a >> Vertex_b >> weight ) 
        {
        
            if (weight < 0)
            {
                cout << "There are negative values, thus Dijkstra cannot be performed..." << endl;
                cout << "Terminating program...." << endl;
                exit(0);
                
            }

            graphLL[Vertex_a].push_back(make_tuple(Vertex_b,weight));
            sort(graphLL[Vertex_a].begin(), graphLL[Vertex_a].end()); 
            graphLL[Vertex_b].push_back(make_tuple(Vertex_a,weight));
            sort(graphLL[Vertex_b].begin(), graphLL[Vertex_b].end());

        }



    } 

    void dijkstra_heapado(int start, int numberVertex) 
    {

        priority_queue < tuple <int, float> > heapgraph;

        vector<float> dist(numberVertex+1, numeric_limits<float>::infinity());
        vector<int> position(numberVertex, 0);

        tuple<int, float> u;
        list<int> explored, found;

        explored.push_back(start);
        found.push_back(start);

        dist[start] = 0;

        while (explored.size() != dist.size())
        {

            for (const auto& v : graphLL[start]) 
            {
                
                if (dist[get<0>(v)] > (dist[start] + get<1>(v))) //contando duas vezes por isso nao fica igual exp e dist
                {

                    dist[get<0>(v)] = dist[start] + get<1>(v);
                    heapgraph.push(make_tuple(get<0>(v),dist[get<0>(v)]));

                }
                
            }
            explored.push_back(start);
            u = heapgraph.top();
            start = get<0>(u);
            heapgraph.pop();

            
        }

        for(const auto& i: dist) {
            cout << i << endl;
        }
        
    }

    void dijkstra(int start, int numberVertex) 
    {

        vector<float> dist(numberVertex, numeric_limits<float>::infinity());
        vector<float> cost(numberVertex, 0.0);
        list<int> explored, found;

        explored.push_back(start);
        found.push_back(start);

        dist[start] = 0;
        
//alteracao
        while (explored.size() != dist.size())
        {

            for (const auto& v : graphLL[start]) 
            {

                if (std::find(explored.begin(), explored.end(), get<0>(v) ) == explored.end()) 
                {
                    found.push_back(get<0>(v));
                }
                
                if (dist[get<0>(v)] > (dist[start] + get<1>(v))) 
                {
                    dist[get<0>(v)] = dist[start] + get<1>(v);
                }
                
                if (cost[get<1>(v)] <= get<1>(v)) //prim
                {
                    cost[get<1>(v)] = get<1>(v);
                    cout << start << "-" << get<0>(v) << endl;
                } 

            }
   
            start = found.front();
            explored.push_back(found.front());
            found.pop_front();

        }

    }
};

int main() {
    
    int Vertex_a, Vertex_b;

    ifstream infile("grafo_1.txt"); 
    int numberVertex;
    infile >> numberVertex;
    infile.close();

    Graph u(0); 

    clock_t start, end;
    double cpu_time_used;
    start = clock();
	u.graphBuilderAdjacencyVector(Vertex_a, Vertex_b);
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    cout << "\n";
    cout << "Tempo gasto: " << cpu_time_used << endl;
    u.dijkstra_heapado(2, numberVertex);
    
    return 0;

}
