https://practice.geeksforgeeks.org/problems/largest-prime-factor/0

#include<bits/stdc++.h>
using namespace std;
int largest(int n){
    
    int last=-1;
    
    while(n%2==0){
        n=n/2;
        last=2;
    }

    for(int i=3;i*i<=n;i=i+2){
        while(n%i==0){
            n=n/i;
            last=i;
        }
    }
    if(n>2){
        last=n;
    }
    return last;
}
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        cout<<largest(n)<<endl;
    }
}
