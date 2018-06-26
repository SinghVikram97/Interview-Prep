https://practice.geeksforgeeks.org/problems/check-set-bits/0

https://drive.google.com/open?id=1WnLyiqsz0yGGeRbmIoX57ziOkTiRFbd7

bool checkAllSetBits(int n){
        
    // n+1 should be a power of 2
    
    // To check for power of 2
    
    // All powers of 2 have only one set bit so remove that set bit by n&(n-1) method
    
    // And if resultant is zero then it is power of 2
    
    // Doesn't work for n=0
    
    if(n==0){
        return false;
    }
    
    int num=n+1;
    
    if((num&(num-1))==0){
        return true;
    }
    else{
        return false;
    }
    
}
