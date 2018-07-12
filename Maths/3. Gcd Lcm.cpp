https://practice.geeksforgeeks.org/problems/lcm-and-gcd/0

A*B=LCM(A,B)*HCF(A,B)

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
    
        int a,b;
        cin>>a>>b;
        int Gcd=gcd(a,b);
        cout<<(a*b)/Gcd<<" ";
        cout<<Gcd<<endl;
        
    }
}
