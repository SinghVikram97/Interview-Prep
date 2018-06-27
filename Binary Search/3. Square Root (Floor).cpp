https://leetcode.com/problems/sqrtx/description/

Question to ask--> We need floor or ceil of non perfect squares?

https://drive.google.com/open?id=1gZ_UV-sOVtp42JEE7CjTE959cnI6QDLm

Time Complexity=O(Log x)
ll mySqrt(ll x) {
        
        ll start=0,end=x;
        ll mid;
        ll ans;
        ll squared;
        while(start<=end){
            
            mid=(start+end)/2;
            
            squared=mid*mid;
            
            // Perfect square
            if(squared==x){
                return mid;
            }
            
            // Store the ans as we want floor of not perfect square nos
            else if(squared<x){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        // Not a perfect square
        return ans;
 }
