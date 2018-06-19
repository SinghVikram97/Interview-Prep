https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

https://drive.google.com/open?id=1Dn1yJeLgKqCuXs85PDEmUCH8bqUpYf6O

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
        
        int cs=0,ms=INT_MIN;
        int start,end;
        int max_start;  // To store start of maximum subarray
        
        for(int i=0;i<n;i++){
            
            // If current_sum<=0 start our subarray fresh
            if(cs<=0){
                cs=0;
                start=i;  // Update this everything sum becomes less than 0 but
            }
            
            // Add current element to current sum
            cs=cs+v[i];
            
            // If current sum greater than maximum sum update maximum sum
            if(cs>ms){
                ms=cs;
                end=i;   // This works fine only updated if current subarray gets a greater sum than prev array
                max_start=start;  // Update max_start only if current subarray gets a greater sum than prev array
            }
            
        }
        int sum=0;
        for(int i=max_start;i<=end;i++){
            sum=sum+v[i];
        }
        cout<<sum<<endl;
    }
}
