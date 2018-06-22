https://leetcode.com/problems/subsets/description/

WRONG CODE ---->
class Solution {
public:
    void backtrack(vector<int> &nums,int start,vector<int> temp,vector<vector<int> > &finalAns){
        
        
        if(start==nums.size()){
           
            finalAns.push_back(temp);
        }
        
        // Either element in final set or not
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,i+1,temp,finalAns);
            temp.pop_back();
        }        
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;
        vector<vector<int> > finalAns;
        
        backtrack(nums,0,temp,finalAns);
        
        return finalAns;
        
    }


};

CORRECT CODE--->

class Solution {
public:
    void backtrack(vector<int> &nums,int start,vector<int> temp,vector<vector<int> > &finalAns){
        
        // IMP
        finalAns.push_back(temp);
        
        // Either element in final set or not
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,i+1,temp,finalAns);
            temp.pop_back();
        }        
        
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;
        vector<vector<int> > finalAns;
        
        backtrack(nums,0,temp,finalAns);
        
        return finalAns;
        
    }


};
