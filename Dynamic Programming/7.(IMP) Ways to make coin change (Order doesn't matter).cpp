https://leetcode.com/problems/coin-change-2/description/

.................................
BRUTE FORCE   https://drive.google.com/open?id=1ELwzP7luLDEAOR2yHU4fKDxijqhBtlIr
class Solution {
public:
    int ways(int amount,vector<int> &coins,int index){
        
        if(amount==0){
            return 1;
        }
        else if(amount<0){
            return 0;
        }
        // If we enter this condition definitely amount is not zero so we have run out of coins
        else if(index==coins.size()){
            return 0;
        }
        
        // Le sakte ho ya nhi le sakte
        return ways(amount-coins[index],coins,index)+ways(amount,coins,index+1);
        
    }
    int change(int amount, vector<int>& coins) {
        
        return ways(amount,coins,0);
        
    }
};

.....................................
https://leetcode.com/problems/coin-change-2/discuss/141076/Logical-Thinking-with-Clear-Java-Code
(REVERSE LOOP)

DP  https://drive.google.com/open?id=19rL7a_IOeXi__pp-i7X8ZG7sIoUMB42Z

class Solution {
public:
   
    int change(int amount, vector<int>& coins) {
        
        int dp[amount+1];
        
        int n=coins.size();
        
        dp[0]=1;
        
        // Imp to intialize to zero as we are using dp[j]+=dp[j-coins[i]]
        for(int i=1;i<=amount;i++){
            dp[i]=0;
        }
        
        // Assume coins array as 1 based so use i-1 everywhere
        for(int i=1;i<=n;i++){
            
            // Can start j from j=coins[i] and remove the if condition of >=0
            for(int j=1;j<=amount;j++){
                
                 if(j-coins[i-1]>=0){
                    dp[j]+=dp[j-coins[i-1]];
                }
            }
            
        }
        return dp[amount];
    }
};
