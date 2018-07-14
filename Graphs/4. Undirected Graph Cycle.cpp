https://drive.google.com/open?id=125LG3fRsZ46kV63shoOahtXIfYRmnBPb (Algo)
https://drive.google.com/open?id=15xuICxploRZCsYC4aMbuM5snlsfELJVs (IMP)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    private:
        /// Adj List --> maps vertex to --> another vertex and stores the distance of edge b/w them
        unordered_map<T,list<T> > adjList;

    public:
    void addEdge(T u,T v,bool bidir=true);
    void printAdjList();
    bool isCyclic();
    bool DFS(T startVertex,map<T,bool> &visited,T parent);
};

template<typename T>
void Graph<T>::addEdge(T u,T v,bool bidir){

    adjList[u].push_back(v);
    /// Undirected so bidir always true
    if(bidir){
        adjList[v].push_back(u);
    }
}
template<typename T>
bool Graph<T>::DFS(T startVertex,map<T,bool> &visited,T parent){

    visited[startVertex]=true;
    /// Visit neighbours of given vertex if not visited
    for(auto it=adjList[startVertex].begin();it!=adjList[startVertex].end();it++){
             
            // 1. If not visited visit them
            if(!visited[(*it)]){
                DFS((*it),visited,startVertex);
            }
            else{

                /// It means this neighbour already visited so check if this neighbour is a parent of current node
                if((*it)!=parent){
                    /// Not a parent and still visited so cycle
                    return true;
                }
            }
        }
        return false;
}
template<typename T>
bool Graph<T>::isCyclic(){

    /// Start dfs from every vertex not visited
    map<T,bool> visited; /// By default intialized as 0 or false
    for(auto it=adjList.begin();it!=adjList.end();it++){
        /// it->first is a vertex
        // Select parent of start vertex as itself
        if(!visited[it->first]){
                if(DFS(it->first,visited,it->first)){
                    return true;
                }
        }
    }
    return false;
}



int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    if(g.isCyclic()){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}

