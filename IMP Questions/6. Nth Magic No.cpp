https://practice.geeksforgeeks.org/problems/faithful-numbers/0

https://drive.google.com/open?id=1yz70hrKL07f9p0gCpoUShxK9SEcFdTRW

ll nthMagicNo(int n){
    
    ll num=0;
    ll power=1;
    
    while(n!=0){
        
        num=num+(power*(n&1));
        n=n>>1;
        power=power*7;
        
    }
    
    return num;
    
}
