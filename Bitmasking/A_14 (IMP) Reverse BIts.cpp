https://practice.geeksforgeeks.org/problems/reverse-bits/0

https://drive.google.com/open?id=1AS3X-np2aVnvPz15QO_EhdZP3x4LkAi-
https://drive.google.com/open?id=1ek8xpwiG1S5HG7bKS4lttK4XVDeR5vGi

void printReverse(ll num){
    
    ll ans=0;
    
    for(int i=0;i<32;i++){
        
        int lastBit=(num&1);
        ans=(ans<<1)|lastBit;
        num=num>>1;
    }
    cout<<ans<<endl;
}

