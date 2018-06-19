https://practice.geeksforgeeks.org/problems/maximum-product-subarray/0

/// It is not similar to find the max sum in an array.
/// In max sum we can discard the previous sum as soon as it is zero.
/// In multipication , we can not do it as product of two negative numbers become positive numbers

https://drive.google.com/open?id=1BFDhLhrt2Zqu1PzEruYavNbgOXUnYBME
https://drive.google.com/open?id=12xe1MTRQHpHZPJBHWiH_7weKrlsXXEKy

#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int minimum_so_far=1;
        int maximum_so_far=1;
        int global_maximum=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(v[i]>=0)
            {
                 // Include current element in existing subarray or start subarray afresh
                 // Ya toh include karna padega ya iss element se naya subarray start karna padega
                 maximum_so_far=max(maximum_so_far*v[i],v[i]);
                 minimum_so_far=min(minimum_so_far*v[i],v[i]);
            }
            else
            {
                  int product1=minimum_so_far*v[i];  /// Because maximum_so_far=max(minimum_so_far*v[i],v[i])
                  int product2=maximum_so_far*v[i];  /// And minimum_so_far=min(maximum_so_far*v[i],v[i])
                  maximum_so_far=max(product1,v[i]); /// So changing max before assigning to min will produce wrong output
                  minimum_so_far=min(product2,v[i]);
            }
            //cout<<"Max so far "<<maximum_so_far<<" "<<"Min so far "<<minimum_so_far<<" "<<"Global max "<<global_maximum<<endl;
            if(global_maximum<maximum_so_far)
            {
                global_maximum=maximum_so_far;
            }
        }
            cout<<global_maximum<<endl;
    }
}
