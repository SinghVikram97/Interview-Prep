https://leetcode.com/problems/two-sum/description/

https://drive.google.com/open?id=16pfHoeAHkkpSjPLmkvtpjIb8S9uqkYBG
https://drive.google.com/open?id=1mzd0tdoPa0LS4n_KVIbVYSvh242Ic-pB  (IMPPP)

BRUTE FORCE-->
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }

vector<int> twoSum(vector<int>& v, int target) {
        
        int n=v.size();
        // Maps value ---> index
        unordered_map<int,int> myMap;
        
        for(int i=0;i<n;i++){
            
            // If found return the answer
            if(myMap.find(target-v[i])!=myMap.end()){
                
                vector<int> ans;
                ans.push_back(myMap[target-v[i]]);
                ans.push_back(i);
                return ans;
            }
            // Else push this into map
            else{
                myMap[v[i]]=i;
            }
            
        }
    }
