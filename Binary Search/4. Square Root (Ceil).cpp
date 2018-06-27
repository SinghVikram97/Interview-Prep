https://drive.google.com/open?id=1gZ_UV-sOVtp42JEE7CjTE959cnI6QDLm


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
            // Store since we want the ceil
            else if(squared>x){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        // Not a perfect square
        return ans;
    }
