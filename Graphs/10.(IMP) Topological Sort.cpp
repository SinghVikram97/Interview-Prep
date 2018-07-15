//Toplogical sorting--> It is a list such that if i appears in that list all it's dependencies must come before it
//in the list
//https://drive.google.com/open?id=1_Brl4WSE9Xt0tLF7ec1tfbKV8MCDeY1m
//https://drive.google.com/open?id=1flcmfwHebp7zD0PF-A77PthY715pYNDx
//https://drive.google.com/open?id=1jV_fUy6CHAo4-j6kUvDN0Mz0U-RSl65r
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
 private:
    int number_of_vertices;
    unordered_map<T,list<T> > adjList;
 public:
    Graph(int no_of_vertices);
    void addEdge(T V1,T V2);
    void printAdjList();
    void topoSort();
};
template<typename T>
Graph<T>::Graph(int no_of_vertices)
{
    number_of_vertices=no_of_vertices;
}
template<typename T>
void Graph<T>::addEdge(T V1,T V2)
{
    adjList[V1].push_back(V2);  /// Directed graph
}
template<typename T>
void Graph<T>::printAdjList()
{
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        cout<<it->first<<"-->";
        for(auto it1=it->second.begin();it1!=it->second.end();it1++)
        {
            cout<<(*it1)<<" ";
        }
        cout<<endl;
    }
}
template<typename T>
void Graph<T>::topoSort()
{
    unordered_map<T,int> inDegree;
    /// 1.Intialize in-degree of all nodes to 0
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        inDegree[it->first]=0;
    }
    /// 2. Calculate indegree of all nodes
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        for(auto it1=adjList[it->first].begin();it1!=adjList[it->first].end();it1++)
        {
            inDegree[*it1]++;
        }
    }
    queue<T> myQueue;
    /// 3.Enqueue all nodes with in-degree 0
    for(auto it=inDegree.begin();it!=inDegree.end();it++)
    {
        /// it->first is a node with in-degree it->second
        if(inDegree[it->first]==0)
        {
            myQueue.push(it->first);
        }
    }
    /// 4.Start the algo
    while(!myQueue.empty())
    {
        /// Queue contains nodes with in-degree 0
        /// Take an element out of queue
        T node=myQueue.front();
        cout<<node<<"-->";
        myQueue.pop();
        for(auto it=adjList[node].begin();it!=adjList[node].end();it++)
        {
            /// Reduce in-degree of all its children to 0
            inDegree[*it]--;
            /// If in-degree becomes 0 push it to queue
            if(inDegree[*it]==0)        /// Maths and english would both reduce programming's indegree so it would
            {                           /// Only be pushed once as second time its indegree will be -1
                myQueue.push(*it);
            }
        }
    }
}
int main()
{
    int no_of_vertices;
    cout<<"Enter the number of vertices"<<endl;
    cin>>no_of_vertices;
    Graph<string> g(no_of_vertices);
    cout<<"Enter the number of edges"<<endl;
    int no_of_edges;
    cin>>no_of_edges;
    for(int i=0;i<no_of_edges;i++)
    {
        cout<<"Enter vertex1 and vertex2"<<endl;
        string v1,v2;
        cin>>v1>>v2;
        g.addEdge(v1,v2);
    }
    cout<<endl;
    g.topoSort();
}
