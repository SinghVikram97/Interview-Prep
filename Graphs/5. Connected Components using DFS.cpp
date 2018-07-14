FOR UNDIRECTED GRAPH WE HAVE CONNECTED COMPONENETS.
FOR DIRECTED GRAPH WE HAVE STRONGLY CONNECTED COMPONENETS

https://drive.google.com/open?id=133tY8U5Lkhsm8tj6lwfVHx9gcrQ6-QcI
https://drive.google.com/open?id=1L-ujTE3MK9DofdUR5Gende4oahvpuRhD (IMP for directed graph)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    private:
        /// Adj List --> maps vertex to --> another vertex and stores the distance of edge b/w them
        unordered_map<T,list<T> > adjList;
        void dfs_helper(T sourceVertex,unordered_map<T,bool> &visited); /// No need to show to client

    public:
    void addEdge(T u,T v);
    void printAdjList();
    int dfs_connectedComponents();
};

template<typename T>
void Graph<T>::addEdge(T u,T v){

    adjList[u].push_back(v);
    /// Undirected so bidir always true
    adjList[v].push_back(u);
}
template<typename T>
int Graph<T>::dfs_connectedComponents(){
    /// For disconnected graph start from every vertex that is not visited yet
    unordered_map<T,bool> visited;
    int count=0;
    for(auto vertex:adjList){
        if(!visited[vertex.first]){
            dfs_helper(vertex.first,visited);
            count++;       /// Count of connected components
            cout<<endl;
        }
    }
    return count;
}
template<typename T>
void Graph<T>::dfs_helper(T sourceVertex,unordered_map<T,bool> &visited){
    visited[sourceVertex]=true;
    cout<<sourceVertex<<" ";
    /// Visit all it's neighbours if not visited
    for(auto neighbour:adjList[sourceVertex]){
        if(!visited[neighbour]){
            dfs_helper(neighbour,visited);
        }
    }
}
int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(6,7);
    g.addEdge(7,8);
    g.addEdge(9,10);
    cout<<"Number of connected components are: "<<g.dfs_connectedComponents();
}

