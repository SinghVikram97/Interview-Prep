https://leetcode.com/problems/permutations/description/

Can be string also

https://drive.google.com/open?id=1XbqPunwmEcyLqV8io-ORpz25ZRJJP1og
https://drive.google.com/open?id=10dBub9PD45xFRXDmX3qG5mzhng5q4Jsr
https://drive.google.com/open?id=1QnFxsaC_aS3zXAxDYTw3StQQ1TPmdDfA

class Solution {
public:
    // Nums passed by reference to avoid making copies saves space
    void backtrack(vector<int> &nums,int start,vector<vector<int> > &finalAns){
        
        if(start==nums.size()){
            finalAns.push_back(nums);
            return;
        }
        
        
        for(int i=start;i<nums.size();i++){
            
            // Fix every number at start
            swap(nums[i],nums[start]);
            
            // Now find permutation of remaining elements ie [1,2,3] fix 3 at start [3,2,1] now find permutations of [2,1]
            backtrack(nums,start+1,finalAns);  // Carefull not i+1 it is start+1
            // We have fixed start now fix start+1 position not i+1
            
            // Backtrack
            swap(nums[i],nums[start]); // (NUMS passed by reference so we have to backtrack) otherwise we can remove this statement
            // It will still print correct solution although order might be different
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int> > finalAns;
        
        backtrack(nums,0,finalAns);
        
        return finalAns;
        
    }
};
