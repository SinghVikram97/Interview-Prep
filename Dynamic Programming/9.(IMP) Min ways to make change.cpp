https://leetcode.com/problems/coin-change/description/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        long long int dp[amount+1];
        dp[0]=0;  // Notice we have taken 0 here not 1 as opposed to previous problem
        
        for(int i=1;i<=amount;i++){
            
            dp[i]=INT_MAX;
            
            for(int j=1;j<=n;j++){
                
                if(i-coins[j-1]>=0){
                    dp[i]=min(dp[i],1+dp[i-coins[j-1]]);
                } 
            }
            
        }
        // IMP CASE if can't make a change example amount=3 and only coin is 3
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
