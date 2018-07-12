https://practice.geeksforgeeks.org/problems/prime-number/0

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
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
