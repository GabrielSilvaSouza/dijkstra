#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;

typedef struct node
{
    int vertex;
 

    tuple<int, int> e_v;
 
    struct node* next;
 
} Node;


Node* newVertex(int Vertex_a, int Vertex_b, int weight) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->vertex=Vertex_a;
    temp->e_v = make_tuple(weight, Vertex_b);
    temp->next=NULL;
}



void builder(Node** head, int Vertex_a, int Vertex_b, int weight ) {
    
    ifstream infile("grafo_1.txt");




    while(infile >> weight >> Vertex_a >> Vertex_b ) {
        if (newVertex(Vertex_a, Vertex_b, weight) == NULL) {
            Node* start = (*head);
            Node* temp = newVertex(Vertex_a, Vertex_b, weight);
            if (get<0>((*head)->e_v) > weight)
                {
                    temp->next = *head;
                    (*head) = temp;
                }
        }
        else
        {
            Node* start = (*head);
            Node* temp = newVertex(Vertex_a, Vertex_b, weight);

            while (start->next != NULL &&
                get<0>(start->next->e_v) < weight)
            {
                start = start->next;
            }
            
            temp->next = start->next;
            start->next = temp;
        }

    }


    infile.close();
}

 

int main() {


    clock_t start, end;
    double cpu_time_used;

	start = clock();
    
	//graphBuilderAdjacencyVector( numberVertex, graphLL,  Vertex_a, Vertex_b);

    end = clock();

    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
    cout << cpu_time_used;

	

	return 0;
    
}