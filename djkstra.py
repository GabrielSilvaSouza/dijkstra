import queue
import math

from numpy import empty

class NodeLinked(object):
    def __init__(self, vertex):
        self.vertex = vertex
        self.sucessor = None

class Linked(object):

    def __init__(self):
        self.head = None

    def go(self,v):
        p = NodeLinked(v)
            
        f = self.head   
        while (f.sucessor): #find a free slot 
            f = f.sucessor
            
        f.sucessor = p

    def printl(self):
        k = self.head
        if k is None:
            pass
        else:
            print(k.vertex)
            while k.sucessor is not None:
                k = k.sucessor
                print("---> ", k.vertex)

    def runner(self):
        f = self.head   
        while (f.sucessor): 
            f = f.sucessor


def graphBuilderAdjacencyList():
    with open(r'grafo_1.txt') as f:
        numberVertex = int(f.readline())
        graph = [Linked() for i in range(1,numberVertex+2)]

        for line in f:
            vertex_a, vertex_b, weight = line.split()
            vertex_a, vertex_b, weight = int(vertex_a), int(vertex_b), int(weight)
            new_node_1 = NodeLinked(vertex_a)
            new_node_2 = NodeLinked(vertex_b)
            if graph[new_node_1.vertex].head is None:
                graph[new_node_1.vertex].head = new_node_1
                graph[new_node_1.vertex].go((weight, vertex_b)) 

            else:
                    graph[new_node_1.vertex].go((weight, vertex_b))

            if graph[new_node_2.vertex].head is None:
                graph[new_node_2.vertex].head = new_node_2
                graph[new_node_2.vertex].go((weight, vertex_a)) 

            else:
                graph[new_node_2.vertex].go((weight, vertex_a))

                    

    #for i in range(0, len(graph)):
     #           graph[i].printl()

    return graph
'''
def Dijkstra(graph, root):
    s = root-1
    dist = [math.inf]*len(graph)
    S = []
    dist[s] = 0
    while len(S) != len(graph):
        u = graph[root]
'''

                     


if __name__ == "__main__":

    u = graphBuilderAdjacencyList()
    print(u[1].head.sucessor.vertex)


