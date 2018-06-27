https://leetcode.com/problems/sqrtx/description/

https://drive.google.com/open?id=1I1_XxygtsbpL7KOQEQqS_hokg5R28mRh

ll mySqrt(ll x) {
        
        if(x==0){
            return 0;
        }
        
        // Imp start should begin from 1 if we use mid==x/mid method or divide by zero error will occur
        ll start=1,end=x;
        ll mid;
        ll ans;
        while(start<=end){
                       
            mid=(end-start)/2+start;
            
            // By default division is floor
            if(mid==x/mid){
                return mid;
            }
            // Store the no as we want floor
            // By default division is floor
            else if(mid<x/mid){
                
                ans=mid;
                // Move right
                start=mid+1;
            }
            else{
                // Move left
                end=mid-1;
            }
        }
        return ans;
    }
