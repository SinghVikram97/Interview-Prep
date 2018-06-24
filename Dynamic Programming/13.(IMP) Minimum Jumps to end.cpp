https://leetcode.com/problems/jump-game-ii/description/

https://drive.google.com/open?id=1dYYkpsSrjFcRS1nhPGifTb5xGXUqBr0w

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
                
                // Starting from index j can we take nums[j] jumps to reach ith index or beyond it
                if(j+nums[j]>=i){
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
        }
        cout<<endl;
        return dp[n-1];        
    }
};
