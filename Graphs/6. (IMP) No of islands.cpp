https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

https://drive.google.com/open?id=1AowrstA1A1D_uS5buSP4XMtW9lfK0iA7
https://drive.google.com/open?id=1PLmVJfYwgeHVqE-fTs5k6J9XYHVcTs-S
https://drive.google.com/open?id=1PRSoTTTq7gsEvVSh91NeAFb6UVDYu7YG

TIME COMPLEXITY--> SIZE OF MATRIX --> O(N*M)

bool canNeighbour(vector<vector<int> > &grid,int i,int j){
    
    // Can be neighbour/connected vertex if it is not out of bounds and it is a 1
    int N=grid.size();
    int M=grid[0].size();
    
    if(i>=0 && i<N && j>=0 && j<M && grid[i][j]==1){
        return true;
    }
    else{
        return false;
    }
    
}
void dfs( vector<vector<int> > &grid, vector<vector<bool> > &visited,int i,int j){
    
    // Mark node as visited
    visited[i][j]=true;
    
    // Visit it's neighbours
    
    vector<int> row={-1, -1, -1,  0, 0,  1, 1, 1};
    vector<int> col={-1,  0,  1, -1, 1, -1, 0, 1};
    
    for(int k=0;k<8;k++){
        int rowNo=i+row[k];
        int colNo=j+col[k];
        
        // If it can be neighbour and it's not visited visit it
        if(canNeighbour(grid,rowNo,colNo) && !visited[rowNo][colNo]){
            dfs(grid,visited,rowNo,colNo);
        }
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
    /// Convert to vector for easy passing to functions
    vector<vector<int> > grid(N,vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            grid[i][j]=A[i][j];
        }
    }
    
    
    vector<vector<bool> > visited(N,vector<bool>(M));  /// Intialized as false by default
    
    /// Start dfs from each 1 which hasn't been visited yet
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                dfs(grid,visited,i,j);
                count++;
            }
        }
    }
    return count;
}
