https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
https://drive.google.com/open?id=1eX8kHrU7o9qqjTbkD3OyWd0d8mGBtzOT 

I interpret the problem in this way, we know everyday's price, thus, we buy a stock, wait its price go up and 
sell it before its price go down. Everytime we sell it at the peak point, thus we earn most money

** We buy only if it price doesn't do down next day ex [7,1,5,3,6,4] We don't buy 7


Look at the solution explaination at leetcode for why we sell the stock at its' peak and not wait for another peak?
https://drive.google.com/open?id=1r9D4szX2hCQYOfo0FKZu7A02_BE6tvSN

Also look at one liner solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        // Keeps track of previous stock we have bought
        int prevStock=-1;
        int profit=0;
        // Till n-1 as we are checking next element
        for(int i=0;i<n-1;i++){
            
            // It means we have to sell the stock if we have bought previously
            if(prices[i]>prices[i+1]){
                
                // We haven't bought a stock yet ex. [7,6,4,3,2,1]
                if(prevStock==-1){
                    continue;
                }
                // Sell the stock and set prevStock to -1 to indicate we don't have any stock
                else{
                     profit+=(prices[i]-prevStock);
                     prevStock=-1;
                }
            }
            // It means price will further increase so keep moving forward
            else{
                
                // It means we haven't bought any stock so buy ex. [1,2,3,4,5]
                if(prevStock==-1){
                    prevStock=prices[i];
                }
                // Keep moving forward
                else{
                    continue;
                }
            }
            
        }
        // For last case ex. [7,1,5,3,6,8] here we buy the stock at 3 but prices increase till 8 so end of array so sell
        // But don't need it for ex. [7,1,5,3,6,4]
        if(prevStock!=-1){
            profit+=prices[n-1]-prevStock;
        }        
        return profit;
    }
};
