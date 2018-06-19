https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

https://drive.google.com/open?id=1ulOcLKcLn3GTnZ_oD5rSD1nqsWu5QXNL

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
        
        for(int i=0;i<n;i++){
            
            // If current_sum<=0 start our subarray fresh
            if(cs<=0){
                cs=0;
            }
            
            // Add current element to current sum
            cs=cs+v[i];
            
            // If current sum greater than maximum sum update maximum sum
            if(cs>ms){
                ms=cs;
            }
            
        }
        cout<<ms<<endl;
    }
    

}
