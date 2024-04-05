#include<iostream>
using namespace std;
class graph{
    public:
    int data;
    graph*next;

};
graph*adj_list[100];
void add_vertex(int vertex){
     graph*newnode=new graph();
     newnode->data=vertex;
     newnode->next=NULL;
     adj_list[vertex]=newnode;

}
void add_edges(int vertex1 ,int vertex2, bool isdirected){
    graph*newnode1=new graph();
    newnode1->data=vertex2;
    newnode1->next=adj_list[vertex1]->next;
    adj_list[vertex1]->next=newnode1;
    if(!isdirected){
        graph*newnode2= new graph();
        newnode2->data=vertex1;
        newnode2->next=adj_list[vertex2]->next;
        adj_list[vertex2]->next=newnode2;
    }
}
void DFSutil(int vertex,bool visited[]){
// mark the current vertex as visited
visited[vertex]=true;
cout<<vertex<<"";
//traverse all the vertices adjacent to this vertex
graph*currentnode=adj_list[vertex];
while(currentnode!=NULL){
int adjacentVertex=currentnode->data;
if(!visited[adjacentVertex]){
    DFSutil(adjacentVertex,visited);
}
currentnode=currentnode->next;

}

}
void DFS(int vertex){
    //mark all vertices as not visited
    bool visited[100]={false};
    //call the recursive utility function to perform dfs traversal
    DFSutil(vertex,visited);

}
int main(){
    add_vertex(0);
    add_vertex(1);
    add_vertex(2);
    add_vertex(3);
    
    add_edges(0,1,false);
    add_edges(1,2,false);
    add_edges(2,3,false);
    add_edges(3,0,false);
    DFS(0);
    return 0;
}
