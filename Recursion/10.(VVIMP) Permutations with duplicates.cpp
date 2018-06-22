https://leetcode.com/problems/permutations-ii/description/

https://drive.google.com/open?id=1JOErCkCCJDq1ZuFsfEw9xuvHmIbC0SA0
https://drive.google.com/open?id=1I57bNCi1quNz0F9yZ_MSAZS4zi5mkfyU
https://drive.google.com/open?id=1Cvv5R_QpBSD0vpSUZyLHjw6G7_zBptV6

class Solution {
public:
    void backtrack(vector<int> &nums,int start,vector<vector<int> > &finalAns){
        
        if(start==nums.size()){
            finalAns.push_back(nums);
            return;
        }
        
        unordered_set<int> s;
        for(int i=start;i<nums.size();i++){
            
            // If same element already made head ignore this element
            if(s.find(nums[i])!=s.end()){
                continue;
            }
            
            s.insert(nums[i]);
            
            // Fix every number at start
            swap(nums[i],nums[start]);
            
            // Now find permutation of remaining elements ie [1,2,3] fix 3 at start [3,2,1] now find permutations of [2,1]
            backtrack(nums,start+1,finalAns);  // Carefull not i+1 it is start+1
            
            // Backtrack
            swap(nums[i],nums[start]);
            
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        // Duplicates so 1st sort
        sort(nums.begin(),nums.end());
        
        vector<vector<int> > finalAns;
        
        backtrack(nums,0,finalAns);
        
        return finalAns;
    }
};
