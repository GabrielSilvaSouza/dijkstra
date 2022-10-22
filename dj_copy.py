import queue
import math

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

#here
    def paritionLast(self, s, e):

        if (s.vertex[0] == e.vertex[0] or s == None or e == None):
            return s
        
        pivot_prev = s
        print((pivot_prev.vertex))
        curr = s
        pivot = e.vertex[0]
        #print(e.vertex)

        while (s != e):
            if (s.vertex[0] < pivot):
 
                # keep tracks of last modified item
                pivot_prev = curr
                temp = curr.vertex
                curr.vertex = s.vertex
                s.vertex = temp
                curr = curr.sucessor
            s = s.sucessor
 
        temp = curr.vertex
        curr.sucessor = pivot
        e.vertex = temp
        
        return pivot_prev


    def sort(self, s, e):
        
        
        if(s == None  or s.vertex[0] == e.vertex[0]):
            return

        pivot_prev = self.paritionLast(s, e)
        
        self.sort(s, pivot_prev)

        if(pivot_prev != None and pivot_prev == s):
            
            
            self.sort(pivot_prev.sucessor, e)

        elif (pivot_prev != None and pivot_prev.sucessor != None):
            self.sort(pivot_prev.sucessor.sucessor, e)
    
def runner(node):
    f = node.head
    while (f.sucessor  != None): #find a free slot 
        f = f.sucessor
    
    return f


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

                #k = runner(graph[new_node_1.vertex])
                #print(graph[new_node_1.vertex].head.sucessor)
                #graph[new_node_1.vertex].sort(graph[new_node_1.vertex].head.sucessor, k)
                
            else:
                #print('thought')
                graph[new_node_1.vertex].go((weight, vertex_b))

                #k = runner(graph[new_node_1.vertex])
                #print(graph[new_node_1.vertex].head.sucessor)
                #graph[new_node_1.vertex].sort(graph[new_node_1.vertex].head.sucessor, k)
                    
            
            if graph[new_node_2.vertex].head is None:
                #print('thought')
                graph[new_node_2.vertex].head = new_node_2
                graph[new_node_2.vertex].go((weight, vertex_a))

                #k = runner(graph[new_node_2.vertex])
                #print(graph[new_node_2.vertex].head.sucessor)
                #graph[new_node_2.vertex].sort(graph[new_node_2.vertex].head.sucessor, k)
                
               
            else:
               
                graph[new_node_2.vertex].go((weight, vertex_a))

                #k = runner(graph[new_node_2.vertex])
                #print(graph[new_node_2.vertex].head.sucessor)
                #graph[new_node_2.vertex].sort(graph[new_node_2.vertex].head.sucessor, k)
                

    for i in range(0, len(graph)):
                graph[i].printl()

    return graph               


if __name__ == "__main__":

    u = graphBuilderAdjacencyList()
    print(u[1].head.sucessor.vertex[0])


