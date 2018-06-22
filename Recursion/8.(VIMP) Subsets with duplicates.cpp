https://leetcode.com/problems/subsets-ii/description/

Same as combination sum just don't forget to sort in any question if you are skipping duplicates

class Solution {
public:
     void backtrack(vector<int> &nums,int start,vector<int> temp,vector<vector<int> > &finalAns){
        
        // IMP
        finalAns.push_back(temp);
        
        // Either element in final set or not
        for(int i=start;i<nums.size();i++){
            
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            
            temp.push_back(nums[i]);
            backtrack(nums,i+1,temp,finalAns);
            temp.pop_back();
        }        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int> temp;
        vector<vector<int> > finalAns;
        
        backtrack(nums,0,temp,finalAns);
        
        return finalAns;
        
    }
};
