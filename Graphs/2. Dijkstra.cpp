https://drive.google.com/open?id=1mChe9tSeXq_RK1dSrzKdO05Kq8PokJIo
https://drive.google.com/open?id=11q1ayPGSOeibf_8usRKxSb6nNjMv5PpF
https://drive.google.com/open?id=1-rjLcL_ylq3tgwpuo-14YeppliT3-mgT
https://drive.google.com/open?id=1qnOBEEXxYIrg83JIsbBGdyhjG7Fh9IKX (Priority_queue vs set C++)


*************************************************************
IMP-> We do not need to keep track of whether a vertex is "done/finalized" ("visited") as in the Wikipedia description, 
      since re-reaching such a vertex will always fail the relaxation condition (when re-reaching a "done/finalized" vertex, 
      the new distance will never be less than it was originally), so it will be skipped anyway.
*************************************************************


#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    private:
        /// Adj List --> maps vertex to --> another vertex and stores the distance of edge b/w them
        unordered_map<T,list<pair<T,int> > > adjList;

    public:
    void addEdge(T u,T v,int dist,bool bidir=true); // Only need to specify default parameter here
    void printAdjList();
    void dijkstra(T sourceVertex);
};

template<typename T>
void Graph<T>::addEdge(T u,T v,int dist,bool bidir){  // Don't specify default parameter here

    adjList[u].push_back(make_pair(v,dist));
    if(bidir){
        adjList[v].push_back(make_pair(u,dist));
    }
}
template<typename T>
void Graph<T>::dijkstra(T sourceVertex){

    /// Maps/Stores the final distance of nodes from source vertex
    unordered_map<T,int> dist;

    /// Intialize all distances to INF
    for(auto it=adjList.begin();it!=adjList.end();it++){
        /// it->first are vertices
        dist[(it)->first]=INT_MAX;
    }

    /// Intialize the distance of source vertex as 0
    dist[sourceVertex]=0;

    /// Take a set to find out which node at minimum distance
    set<pair<int,T> >s;  /// 1st element of pair as distance as set sorts on basis of 1st element

    /// Insert source vertex into set to intiate the algo
    s.insert(make_pair(0,sourceVertex));

    while(!s.empty()){

        auto minDist=*(s.begin());  /// minDist a pair of dist and node
        /// This node's distance finalized so erase from set
        s.erase(s.begin());

        /// Explore it's neighbours and update their distance
        int nodeDist=minDist.first; /// distance of node from sourceVertex
        T node=minDist.second;

        /// each it in adjlist of node is a pair of (childnode,dist)
        for(auto it=adjList[node].begin();it!=adjList[node].end();it++){

            if(nodeDist+(it->second)<dist[it->first]){

                /// Update distance in both dist and set
                /// Set updation not possible so first erase and then insert again in set
                dist[it->first]=nodeDist+(it->second);

                /// Find vertex with old distance and erase
                auto f=s.find(make_pair(dist[it->first],it->first));

                if(f!=s.end()){
                    s.erase(f);
                }

                /// Insert it with new distance
                s.insert(make_pair(nodeDist+(it->second),it->first));
            }
        }
    }

    /// Print all the distances
    for(auto d=dist.begin();d!=dist.end();d++){
        cout<<d->first<<" located at "<<d->second<<endl;
    }
}



int main(){

    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.dijkstra(1);
}

