https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    
    void backtrack(int k,int start,int target,vector<int> temp,vector<vector<int> > &final){
        
        
        if(target<0){
        
            return;
        }
        // We only want combinations of size k
        if(temp.size()>k){
            return;
        }
        // If we remove these 2 temp.size() conditions we get all combinations irrespective of size of list
        else if(target==0 && temp.size()==k){
            final.push_back(temp);
        }
        
        // We can only use numbers from 1 to 9 and no number more than once
        for(int i=start;i<=9;i++){
            
            // i se 9 tak kuch bhi lo
            temp.push_back(i);
            
            // Now remaining sum from i+1 to 9
            backtrack(k,i+1,target-i,temp,final);
            
            // Try another number 
            temp.pop_back();            
            
        }
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        // K is the size of the resultant list
        vector<int> temp;
        
        // N is the target
        
        vector<vector<int> > final;
        
        // Intially start is 1
        backtrack(k,1,n,temp,final);
        
        // return final
        return final;
    }
};
