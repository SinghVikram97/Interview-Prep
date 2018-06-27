/// TRY FOR 10 wrong answer if we don't use ceil and double
https://drive.google.com/open?id=1aj8nWAMmaj_iI9Sgi0G568vjd6cqvI-m

 ll mySqrt(ll x) {
        
        if(x==0){
            return 0;
        }
        
        ll start=1,end=x;
        ll mid;
        ll ans;
        while(start<=end){
                       
            mid=(end-start)/2+start;
            
            // By default division is floor so use ceil
            // Use double so that it doesn't truncate division before using ceil
            if(mid==ceil((double)x/mid)){
                return mid;
            }
            // Store the no as we want ceil
            // By default division is floor
            else if(mid>ceil((double)x/mid)){
                
                ans=mid;
                // Move left
                end=mid-1;
            }
            else{
                // Move right
                start=mid+1;
            }
        }
        return ans;
    }
