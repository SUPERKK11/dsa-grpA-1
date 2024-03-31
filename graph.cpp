// this code is based on adjency list representation of graph 
#include<iostream>
using namespace std;

class graph {
public:
    int data;
    int weight;
    graph* next;
};

graph* arr[100];

void add_vertex(int vertex) {
    graph* newnode = new graph();
    newnode->data = vertex;
    newnode->next = nullptr;
    arr[vertex] = newnode;
}

void add_edge(int vertex1, int vertex2, int weight, bool isDirected) {
    graph* newnode1 = new graph();
    newnode1->data = vertex2;
    newnode1->weight = weight;
    newnode1->next = arr[vertex1]->next;
    arr[vertex1]->next = newnode1;

    if (!isDirected) {
        graph* newnode2 = new graph();
        newnode2->data = vertex1;
        newnode2->weight = weight;
        newnode2->next = arr[vertex2]->next;
        arr[vertex2]->next = newnode2;
    }
}

int main() {
    return 0;
}
