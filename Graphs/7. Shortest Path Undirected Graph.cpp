USING BFS--> Single source shortest path to all vertices

https://drive.google.com/open?id=1FdCDWzB9noSoEc0Tf-ZtwCIEGmJaeU6J (Conditions to work)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    private:
        unordered_map<T,list<T> > adjList;
        void bfs(T source,map<T,int> &dist);

    public:
    void addEdge(T u,T v);
    void printAdjList();
    int distance(T source,T destination);
};

template<typename T>
void Graph<T>::addEdge(T u,T v){

    adjList[u].push_back(v);
    /// Undirected so bidir always true
    adjList[v].push_back(u);
}
template<typename T>
void Graph<T>::bfs(T source,map<T,int> &dist){

    queue<T> q;
    q.push(source);
    dist[source]=0;

    while(!q.empty()){

        /// Pop the front element
        T vertex=q.front();
        q.pop();

        /// Visit its' neighbours if not visited
        for(auto neighbour:adjList[vertex]){
            if(dist[neighbour]==-1){
                q.push(neighbour);
                dist[neighbour]=dist[vertex]+1;
            }
        }

    }

}
template<typename T>
int Graph<T>::distance(T source,T destination){

    /// By default intialized by 0
    map<T,int> dist; /// Stores distance b/w source vertex and all other vertices and works as visited array too
    /// Mark distance as not calculated yet
    for(auto vertex:adjList){
        dist[vertex.first]=-1;  /// IMP-(Don't intialize to 0) as 1 will push 0 again as it's distance will be zero. So if not visited keep it as -1
    }
    bfs(source,dist);    /// Start bfs from source vertex
    for(auto vertex:adjList){
        cout<<"Distance between vertex 0 and vertex "<<vertex.first<<" is "<<dist[vertex.first]<<endl;
    }
    return dist[destination];

}
int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);

    int source,dest;
    cin>>source>>dest;

    cout<<"Distance is "<<g.distance(source,dest);

}

