https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
We need to find difference between max peak and lowest valley

........................................
BRUTE FORCE
https://drive.google.com/open?id=1ka4G1_S3DTXDHfPYsHqWGCvwEQlkiWqt

int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int max_profit=0;
        int profit;
        for(int i=0;i<n-1;i++){
            // Buy ith stock and try to sell it at every day after it
            
            for(int j=i+1;j<n;j++){
                
                // If we sell ith stock on jth day
                profit=prices[j]-prices[i];
                if(profit>max_profit){
                    max_profit=profit;
                    
                }
            }
            
        }
        return  max_profit;   
    }
    
    ...................................
    DP
    
    https://drive.google.com/open?id=1tcjpbuErL3NOfIIt3l84uyaQ5XfkOMww
    https://drive.google.com/open?id=1m-7PLUf76gZGLaBL_P6zfbeOLjIqKOrO
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        // n=1 as can't buy and sell on same day
        if(n==0 || n==1){
            return 0;
        }
        
        int dp[n];
        
        dp[0]=0;  // n=1 as can't buy and sell on same day
        
        int min_price=prices[0];
        
        for(int i=1;i<n;i++){
            
            dp[i]=max(dp[i-1],prices[i]-min_price);
            min_price=min(min_price,prices[i]);
            
        }
        
       return dp[n-1];        
    }
    
    ..................................
    Since dp[i-1] is just one variable we can keep it a variable prevProfit
    
     int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        // n=1 as can't buy and sell on same day
        if(n==0 || n==1){
            return 0;
        }
        
        int prevProfit=0;
        
        int profit;
        
        int min_price=prices[0];
        
        for(int i=1;i<n;i++){
            
            profit=max(prevProfit,prices[i]-min_price);
            min_price=min(min_price,prices[i]);
            prevProfit=profit;
            
        }
        
       return profit;
    }
