https://leetcode.com/problems/01-matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        
        // BFS
        // New coordinates or neighbours
        vector<int> newX = {-1, 0, 1, 0}; 
        vector<int> newY = {0, -1, 0, 1}; 
        
        // Make distance matrix
        
        int m=v.size();
        int n=v[0].size();
        
        vector<vector<int> > dist(m,vector<int>(n));
        
        
        // Insert all 0's into queue
        queue<pair<int,int> > mq;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=INT_MAX-5;
                if(v[i][j]==0){
                    dist[i][j]=0;
                    mq.push(make_pair(i,j));
                }
            }
        }
        
      
        
        // Start bfs
        
        while(!mq.empty()){
            
            pair<int,int>  frontEle=mq.front();
            mq.pop();
            
            int x=frontEle.first;
            int y=frontEle.second;
            
            for(int i=0;i<4;i++){
                
                int r=x+newX[i];
                int c=y+newY[i];
                
                if(r<m && r>=0 && c<n && c>=0 && dist[r][c]>dist[x][y]+1){
                    dist[r][c]=1+dist[x][y];
                    mq.push(make_pair(r,c));
                }
                
                
            }
            
        }
        return dist;
        
    }
};
