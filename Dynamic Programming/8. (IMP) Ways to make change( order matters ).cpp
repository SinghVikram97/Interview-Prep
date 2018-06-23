class Solution {
public:
   
    int change(int amount, vector<int>& coins) {
        
        int dp[amount+1];
        
        int n=coins.size();
        
        dp[0]=1;
        
        for(int i=1;i<=amount;i++){
            
            dp[i]=0;
            
            for(int j=1;j<=n;j++){
                
                if(i-coins[j-1]>=0){
                    dp[i]+=dp[i-coins[j-1]];
                }              
            }
        }
        return dp[amount];
    }
};
