https://leetcode.com/problems/counting-bits/description/

https://drive.google.com/open?id=1QvqiDCgwvVzOf_nZ1pAiWFOrFTuleCia

class Solution {
public:
    vector<int> countBits(int num) {
        
        if(num==0){
            return {0};
        }
        else if(num==1){
            return {0,1};
        }
        
        vector<int> ans(num+1);
        
        ans[0]=0;
        ans[1]=1;
        
        for(int i=2;i<=num;i++){
            
            if(i%2==0){
                ans[i]=ans[i/2];
            }
            else{
                ans[i]=ans[i/2]+1;
            }
            
        }
        return ans;       
    }
};
