https://leetcode.com/problems/combination-sum-ii/description/

https://drive.google.com/open?id=1OQGNOrS92TUQwZKes7Zxmz7L2GLg69sC
https://drive.google.com/open?id=1ucly7l8EJxMb6qOGkmNsHBI4C6dozGYa

https://leetcode.com/problems/combination-sum-ii/discuss/16862/C++-backtracking-solution-with-detailed-explanation
(For duplicates)


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
        
        for(int i=start;i<nums.size();i++){
            
            // ex if 1,2,2,2,5
            // See photo
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            // 1. Take the number
            temp.push_back(nums[i]);
            backtrack(nums,i+1,target-nums[i],temp,ans); // Pass start as i as we can take that number again
            // 2. Don't take the number 
            temp.pop_back();       
        }
        
        
    }
     
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > ans;
        vector<int> temp;
        
        backtrack(candidates,0,target,temp,ans);
        
        return ans;
    }
};
