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
