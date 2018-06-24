https://leetcode.com/problems/climbing-stairs/description/

https://drive.google.com/open?id=1Q1P-MI-fXKO-586V3mVLGK16W4vr4Jo5

class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0 || n==1){
            return 1;
        }
        
        int dp[n+1];
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        
        return dp[n];
        
    }
};
