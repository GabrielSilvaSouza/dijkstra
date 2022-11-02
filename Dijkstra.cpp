#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include <tuple>

using namespace std;

class Graph { 

    int root; 

    vector< tuple <int, float> > * graphLL;  

    int numberVertex;

public:

    Graph(int n) 
    {

        ifstream infile("grafo_W_1_1.txt"); 
        int numberVertex;
        infile >> numberVertex;
        infile.close();

        //this->numberVertex = numberVertex;

        graphLL = new vector< tuple <int, float> > [numberVertex+1];

    }

    void graphBuilderAdjacencyVector(int Vertex_a, int Vertex_b) 
    {
            
        float weight;
        ifstream infile("grafo_W_1_1.txt"); 
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
    

    void dijkstra(int start, int numberVertex) 
    {

        vector<float> dist(numberVertex, numeric_limits<float>::infinity());
        vector<float> cost(numberVertex, 0.0);
        list<int> explored, found;

        explored.push_back(start);
        found.push_back(start);

        dist[start] = 0;
        

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
                
                if (cost[get<1>(v)] <= get<1>(v)) 
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

    void dijkstra_heapado(int start, int numberVertex) {
        
    }

};

int main() {
    
    int Vertex_a, Vertex_b;

    ifstream infile("grafo_W_1_1.txt"); 
    int numberVertex;
    infile >> numberVertex;
    infile.close();
 

    Graph u(0); 

	u.graphBuilderAdjacencyVector(Vertex_a, Vertex_b);
    u.dijkstra(185,numberVertex+1);
    
    return 0;

}


                /*
                cout << "avicci" << endl;
                exit(0);
                */  

            /*
            auto it = std::find_if(graphLL[start].begin(), graphLL[start].end(), [](const auto& e) {return std::get<0>(e) == start;});
            explored.push_back(get<0>(it));
            */


        /*
        for (const auto& i : graphLL[67] ) {
            cout << get<0>(i) << endl;
        }
        */

               /*

        for (const auto& i : dist ) 
        {
            cout << i << endl;
        }

        */