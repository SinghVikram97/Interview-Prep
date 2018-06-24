https://leetcode.com/problems/jump-game-ii/description/

class Solution {
public:
    int jump(vector<int>& nums) {
        
        
        int n=nums.size();
        
        if(n==0){
            return 0;
        }
        
        int dp[n];
        
        dp[0]=0;
        
        for(int i=1;i<n;i++){
            
            dp[i]=INT_MAX;
            
            for(int j=i-1;j>=0;j--){
                
                if(j+nums[j]>=i){
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
        }
        cout<<endl;
        return dp[n-1];        
    }
};
