https://practice.geeksforgeeks.org/problems/prime-number/0

https://drive.google.com/open?id=1lEjgcvaY8VIN-zd3vVBSeiFVpq7lGAJb

bool isPrime(int n){
    if(n==0 || n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    if(n%2==0){
        return false;
    }
    // Check only till under root n
    // as if n%a=0
    // it means n=a*b ie. both a and b divide n
    // now one of them will be smaller than n and one should be greater than n
    
    for(int i=3;i*i<=n;i=i+2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
