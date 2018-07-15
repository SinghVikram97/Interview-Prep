https://leetcode.com/problems/longest-increasing-subsequence/description/

Brute force generate all subsequences --- O(2^n) see leetcode solution for brute force

Recursive solution-->
class Solution {
public:
    void backtrack(vector<int> &nums,int start,int prev,int length,int &maxLength){
        
       
        if(length>maxLength){
            maxLength=length;
        }
        
        for(int i=start;i<nums.size();i++){
            
            if(start==0){
                backtrack(nums,i+1,nums[i],length+1,maxLength);
            }   
            else{
                if(nums[i]>prev){
                    backtrack(nums,i+1,nums[i],length+1,maxLength);
                }
            }            
        }               
    }
    int lengthOfLIS(vector<int>& nums) {
        int maxLength=-1;
        backtrack(nums,0,-1,0,maxLength);
        return maxLength;
        
    }
};

DP-->
    
https://drive.google.com/open?id=1xw5nK1Oq089UJm5EPwMaZ1CO79Iub3eH
https://drive.google.com/open?id=1MUYqnzga4jhCj5JGxid7Lb_e8K8f4JD0
https://drive.google.com/open?id=1suB4Rklme21yppYF5s65z6KnXHUC6dAh

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
       
        int n=nums.size();
        if(n==0){
            return 0;
        }
        
        int dp[n];  // dp[i] denoted length longest increasing subsequence which ends at nums[i]
        
        dp[0]=1; // Single character also a increasing subsequence 
        
        for(int i=1;i<n;i++){
            
            // Decide length longest increasing subsequence which ends at nums[i]
            // Min can be nums[i] itself
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                
                // Condition for increasing subsquence
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);  // Longest increasing subsquence ending at j + include nums[i] in it as nums[i]>nums[j]
                }                
            }
        }
        
        // Now we have length of longest increasing subsquences ending at i
        // Our LIS can end at any i
        int length=1;
        for(int i=0;i<n;i++){
            length=max(length,dp[i]);
        }
        return length;
    }
};
