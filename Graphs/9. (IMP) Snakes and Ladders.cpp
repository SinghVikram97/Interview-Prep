https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0

Same as finding shortest path using bfs in unweighted graph/undirected graph

https://drive.google.com/open?id=1kxysKx03w-H9Zvy02EC1GxWwYHSj6CE0
https://drive.google.com/open?id=1Vx0Mg6Blle6Nx50wrIEbgDS0XvLpdAuc

#include<bits/stdc++.h>
using namespace std;
struct cell{
    int no; /// cell no
    int dist; /// dist from 1 (starting point)
    cell(int n,int d){
        no=n;
        dist=d;
    }
};
int bfs(int m,int n,vector<int> &board){

    int finalCell=m*n;
    // vector<bool> visited(m*n+1)
    unordered_map<int,bool> visited;  // As we can reach more than 30 ex. 25+6=31
    queue<cell> q;

    /// Push start vertex
    q.push(cell(1,0));
    visited[1]=true;

    while(!q.empty()){

     cell temp=q.front();
     q.pop();

     /// Reached 30 or crossed 30. ex. 28 se we throw a dice of 3 we reach 31 directly so >=
     if(temp.no>=finalCell){
         return temp.dist;
     }

     /// Visit all it's neighbours if not visited
     for(int i=1;i<=6;i++){

         int neighbourNo=(temp.no+i)+board[temp.no+i];
         
         if(!visited[neighbourNo]){
             q.push(cell(neighbourNo,temp.dist+1));
             visited[neighbourNo]=true;
          }
       }

    }
    return -1;
}
int main(){

    int t;
    cin>>t;
    while(t--){

        int m,n;        /// m*n board treat as 1d array
        m=5,n=6;
        vector<int> board((n*m)+1); // 1 based indexing
        int num;
        cin>>num;
        for(int i=0;i<num;i++){
            int source,dest;
            cin>>source>>dest;
            board[source]=(dest-source);  // Jump of (dest-source) from source
        }
        cout<<bfs(m,n,board)<<endl;
    }
}
