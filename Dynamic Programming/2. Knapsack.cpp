https://drive.google.com/open?id=1uh81Z7LmKFpVoI0zKzzhCuN8g87ytiYK
https://drive.google.com/open?id=14851LU2AVSZCEVBiaKmIrrC5zay72VPA

int knapsack(int n,int capacity,vector<int> value,vector<int> weight){
    
    // dp[i][j] represents max_value if capacity of knapsack i and items upto jth index
                              
    int dp[capacity+1][n+1];  
    
    // So our answer is dp[capacity][n]
    
    // Base case
    // If no items or capacity of knapsack is zero
    
    for(int i=0;i<=capacity;i++){
        dp[i][0]=0;
    }
    
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }
    
    
    // Since values and weights array 0 based indexing use j-1 everywhere in place of j whenever you use weight and values array to simulate 1 based indexing
    
    for(int i=1;i<=capacity;i++){
        for(int j=1;j<=n;j++){
            
            int option1=INT_MIN; // Take the item INT_MIN because it can't take the item
            // Can only take the item if it's weight less than equal to knapsack's capacity (i)
            
            // Use weight[j]<=i if 1 based indexing
            if(weight[j-1]<=i){
                
                option1=value[j-1]+dp[i-weight[j-1]][j-1];
                
                // 1 based index for values and weights array
                // option1=value[j]+dp[i-weight[j]][j-1];
                
            }
            
            int option2; // Don't take the item
            option2=dp[i][j-1];
            
            dp[i][j]=max(option1,option2);
            
        }
    }
    
    return dp[capacity][n];
    
}
