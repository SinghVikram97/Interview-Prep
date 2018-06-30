https://practice.geeksforgeeks.org/problems/next-permutation/0  

http://www.cplusplus.com/reference/algorithm/next_permutation/

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
        next_permutation(v.begin(),v.end());
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    

}
