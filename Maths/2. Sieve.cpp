https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0

https://drive.google.com/open?id=1aC_LXH5tx3Xn3P5KkvQZfRKaHOCZZLd1

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll max_range=10005;
vector<bool> prime(max_range);
void sieve(){

    // Mark odd numbers as prime and even number as not prime
    for(ll i=0;i<max_range;i++){
        if(i%2==0){
            prime[i]=false;
        }
        else{
            prime[i]=true;
        }
    }
    // 0 and 1 are not prime as 2 is even prime
    prime[0]=false;
    prime[1]=false;
    prime[2]=true;
    
    // Mark out factors of prime nos as false 
    for(ll i=3;i<max_range;i++){
        if(prime[i]){
            for(ll j=i*i;j<max_range;j=j+2*i){
                prime[j]=false;
            }
        }
    }
}
int main(){

    int t;
    cin>>t;
    sieve();
    while(t--){
    
        int n;
        cin>>n;
        for(int i=0;i<=n;i++){
            if(prime[i]){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}
