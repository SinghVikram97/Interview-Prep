https://practice.geeksforgeeks.org/problems/gcd-of-array/0/

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        vector<int> v(n);
        int gcdArray=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            gcdArray=gcd(v[i],gcdArray);
        }
        cout<<gcdArray<<endl;
    }
}
