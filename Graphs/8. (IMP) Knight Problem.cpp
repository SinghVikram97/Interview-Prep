https://www.interviewbit.com/problems/knight-on-chess-board/

https://drive.google.com/open?id=1byyDC7wDDe977hOrpRBFD6egN2BgdKmx

struct cell{
    int x,y;  // Cordinates
    int dist; // Distance from source ie.knight
    
    cell(int i,int j,int d){
        x=i;
        y=j;
        dist=d;
    }
};
bool isValid(int n,int m,int rowNo,int colNo){
    
    /// Board is 1 indexed
    if(rowNo>=1 && rowNo<=n && colNo>=1 && colNo<=m){
        return true;
    }
    else{
        return false;
    }
}
int Solution::knight(int n, int m, int x1, int y1, int x2, int y2){
    
    vector<int> row={-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> col={-1, 1, -2, 2, -2, 2, -1, 1};
    
    /// Board is 1 indexed
    vector<vector<bool> > visited(n+1,vector<bool>(m+1)); // By default intialized to false
    
    queue<cell> q;
    q.push(cell(x1,y1,0)); // Distance of source to source is 0
    visited[x1][y1]=true;
    
    while(!q.empty()){
        
        cell temp=q.front();
        q.pop();
        
        if(temp.x==x2 && temp.y==y2){
            return temp.dist;
        }
        
        // Visit neighbours of temp vertex if not already visited
        for(int i=0;i<8;i++){
          int rowNo=temp.x+row[i];
          int colNo=temp.y+col[i];
          
          if(isValid(n,m,rowNo,colNo) && !visited[rowNo][colNo]){
              q.push(cell(rowNo,colNo,temp.dist+1));
              visited[rowNo][colNo]=true;
          }
          
        }
        
    }
    
    return -1;
}
