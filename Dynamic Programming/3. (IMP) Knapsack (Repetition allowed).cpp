Its an unbounded knapsack problem as we can use 1 or more instances of any resource.
A simple 1D array, say dp[W+1] can be used such that dp[i] stores the maximum value which can achieved using 
all items and i capacity of knapsack. 
Note that we use 1D array here which is different from classical knapsack where we used 2D array.

..................IMP................................................
Here number of items never changes. We always have all items available.
We use 1D array but need to use 2 loops like previous one

int knapsack(int n,int capacity,vector<int> value,vector<int> weight){
    
    int dp[capacity+1];  // dp[i] represents max_value with knapsack of capacity i and using all n items
    // So dp[capacity] is our answer
    
    dp[0]=0;  // Capacity of knapsack is zero
    
    for(int i=1;i<=capacity;i++){
        
        dp[i]=0;  // IMP
        for(int j=1;j<=n;j++){
            
            if(i-weight[j-1]>=0){
                dp[i]=max(dp[i],value[j-1]+dp[i-weight[j-1]]);
            }
        }
    }
    return dp[capacity];
}
