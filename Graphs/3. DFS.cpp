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
    void dfs(T sourceVertex);
};

template<typename T>
void Graph<T>::addEdge(T u,T v){

    adjList[u].push_back(v);
    /// Undirected so bidir always true
    adjList[v].push_back(u);
}
........................................................................
template<typename T>
void Graph<T>::dfs(T sourceVertex){
    /// For disconnected graph start from every vertex that is not visited yet
    unordered_map<T,bool> visited;
    dfs_helper(sourceVertex,visited);
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
............................................................................
int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.dfs(0);
}

