https://practice.geeksforgeeks.org/problems/number-of-paths/0

No of paths=no of paths(i+1,j) + no of paths(i,j+1)
i+1 means going down and j+1 means going right

#include<bits/stdc++.h>
using namespace std;
int ans;
void countPaths(int i,int j,int m,int n){
    
    if(i==m-1 && j==n-1){
        ans++;
        return;
    }
    else if(i>=m || j>=n){
        return;
    }
    else{
        countPaths(i+1,j,m,n);
        countPaths(i,j+1,m,n);
        return;
    }
}
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int m,n;
        cin>>m>>n;
        ans=0;
        countPaths(0,0,m,n);
        cout<<ans<<endl;
    }
}
