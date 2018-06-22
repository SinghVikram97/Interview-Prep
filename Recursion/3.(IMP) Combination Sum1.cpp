https://leetcode.com/problems/combination-sum/description/

https://drive.google.com/open?id=1Y0jofY6ojs3xG-5SC3z2lNOogzYoBrhC

class Solution {
public:
   
    void backtrack(vector<int> &nums,int start,int target,vector<int> temp,vector<vector<int> > &ans){
        
        if(target<0){
            return;
        }
        else if(target==0){
            ans.push_back(temp);
        }
        
        // 2 options for given element to be included in combination or not
        // Remember a element can be used twice
        
        // At any point we can take all the numbers from start to nums.size
        for(int i=start;i<nums.size();i++){
            
            // 1. Take the number
            temp.push_back(nums[i]);
            backtrack(nums,i,target-nums[i],temp,ans); // Pass start as i as we can take that number again
            // 2. Don't take the number 
            temp.pop_back();       
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > ans;
        vector<int> temp;
        
        backtrack(candidates,0,target,temp,ans);
        
        return ans;
        
    }
};
