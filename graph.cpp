// this code is based on adjency list representation of graph 
#include<iostream>

using namespace std;

class Graph {
public:
    int data;
    int weight;
    Graph* next;

    Graph() {
        data = -1;
        weight = 0;
        next = NULL;
    }

    void add_vertex(int vertex){
        Graph* newnode = new Graph();
        newnode->data = vertex;
        newnode->next = NULL;
        vertices[vertex] = newnode;
    }

    void add_edge(int vertex1, int vertex2, int weight){
        Graph* newnode1 = new Graph();
        newnode1->data = vertex2;
        newnode1->weight = weight;
        newnode1->next = vertices[vertex1]->next;
        vertices[vertex1]->next = newnode1;

        // Create a new node for vertex1 and add it to the adjacency list of vertex2 (for undirected graph)
        Graph* newnode2 = new Graph();
        newnode2->data = vertex1;
        newnode2->weight = weight;
        newnode2->next = vertices[vertex2]->next;
        vertices[vertex2]->next = newnode2;
    }

    void display() {
        for (int i = 0; i < 100; ++i) {
            if (vertices[i] != NULL) {
                cout << "Vertex " << i << ": ";
                Graph* current = vertices[i]->next;
                while (current != NULL) {
                    cout << "(" << current->data << ", " << current->weight << ") ";
                    current = current->next;
                }
                cout << endl;
            }
        }
    }

private:
    Graph* vertices[100];
};

int main() {
    Graph graph;
    graph.add_vertex(0);
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);

    graph.add_edge(0, 1, 5);  // Edge between vertex 0 and vertex 1 with weight 5
    graph.add_edge(0, 2, 10); // Edge between vertex 0 and vertex 2 with weight 10
    graph.add_edge(1, 3, 7);  // Edge between vertex 1 and vertex 3 with weight 7
    graph.add_edge(2, 4, 3);  // Edge between vertex 2 and vertex 4 with weight 3

    graph.display();

    return 0;
}
