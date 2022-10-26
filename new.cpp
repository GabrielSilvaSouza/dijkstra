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

    return temp;
}


void nv(Node** head, int Vertex_a, int Vertex_b, int weight ) {
    
        Node* start = (*head);
        Node* temp = newVertex(Vertex_a, Vertex_b, weight);
        if (get<0>((*head)->e_v) > weight)
        {
            temp->next = *head;
            (*head) = temp;
        }
        else
        {
            while (start->next != NULL &&
                get<0>(start->next->e_v) < weight)
            {
                start = start->next;
            }
            
            temp->next = start->next;
            start->next = temp;
        }


}

void builder(){

    int Vertex_a;
    int Vertex_b; 
    int weight;
    int numberVertex;
    ifstream infile("grafo_1.txt");
    infile >> numberVertex;
    vector< int> linkedvec[numberVertex];
    infile >> weight >> Vertex_a >> Vertex_b;
    Node* s = newVertex(Vertex_a, Vertex_b, weight);
    linkedvec[0].push_back(s);

    while(infile >> weight >> Vertex_a >> Vertex_b ) {
        nv(&s, Vertex_a, Vertex_b, weight);
    }

    cout << s->next->vertex;

    infile.close();
}
 

int main() {

    clock_t start, end;
    double cpu_time_used;

	start = clock();
    
    builder();

    end = clock();
    cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;

	return 0;
    
}