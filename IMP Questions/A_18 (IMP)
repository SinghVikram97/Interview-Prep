https://www.geeksforgeeks.org/find-maximum-product-of-a-triplet-in-array/

https://drive.google.com/open?id=1v0Ce3DUSjKcp2RT1yWmL17Pk-GgEkxvZ
https://drive.google.com/open?id=1fliu81Pc5p7xvNgo3c2UkCcYaweW7REM
https://drive.google.com/open?id=1JMbgpE14qTEI3Eux0Vo7Kjw8mB74Yn0Q

O(nlogn)
ll maxProduct(vector<ll> v,int n){
    
    sort(v.begin(),v.end());
    
    ll mP=max(v[n-1]*v[n-2]*v[n-3],v[0]*v[1]*v[n-1]);
    
    return mP;
    
}

O(n)
ll maxProduct(vector<ll> v,int n){
    
    ll max1=INT_MIN,max2=INT_MIN,max3=INT_MIN; // max1>max2>max3
    ll min1=INT_MAX,min2=INT_MAX;  /// min1<min2
    
    for(int i=0;i<n;i++){
        
        if(v[i]>max1){
            max3=max2;
            max2=max1;
            max1=v[i];
        }
        else if(v[i]>max2){
            max3=max2;
            max2=v[i];
        }
        else if(v[i]>max3){
            max3=v[i];
        }
        
        if(v[i]<min1){
            min2=min1;
            min1=v[i];
        }
        else if(v[i]<min2){
            min2=v[i];
        }
    }
    
    return max(max1*max2*max3,min1*min2*max1);
    
}
