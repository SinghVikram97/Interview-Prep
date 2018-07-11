https://practice.geeksforgeeks.org/problems/inversion-of-array/0

https://drive.google.com/open?id=1gbL7vlWe-yiYTYg9DYmCFHTp7u_mY6f_
https://drive.google.com/open?id=14TLPXQpYpwSGCoEPJM2jvGa76j6kyfFr

#include<bits/stdc++.h>
using namespace std;
int merge(vector<int> &target,vector<int> &a,vector<int> &b){
    
    // Merge a and b into target
    int n=a.size();
    int m=b.size();
    int inversionCount=0;
    int i=0,j=0,k=0;
    while(i<n && j<m){
        
        if(a[i]<=b[j]){
            // No inversion
            target[k]=a[i];
            i++;
            k++;
        }
        else{
            // Inversions from i to n-1
            inversionCount+=n-i;
            target[k]=b[j];
            j++;
            k++;
        }
        
    }
    while(i<n){
        target[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        target[k]=b[j];
        j++;
        k++;
    }
    
    return inversionCount;
}
int mergeSort(vector<int> &v){
    
    int n=v.size();
    if(n==1){
        return 0;
    }
    
    // Divide into 2 parts 
    int mid=(n-1)/2; 
    
    // Left part-> [0.....mid]
    vector<int> left;
    for(int i=0;i<=mid;i++){
        left.push_back(v[i]);
    }
    
    // Right part-> [mid+1 .... n-1]
    vector<int> right;
    for(int i=mid+1;i<=n-1;i++){
        right.push_back(v[i]);
    }
    
    // Sort these 2 arrays
    int leftPartInversions=mergeSort(left);
    int rightPartInversions=mergeSort(right);
    
    // Merge these 2 arrays
    int mergeInversions=merge(v,left,right);
    
    return leftPartInversions+rightPartInversions+mergeInversions;
    
    
}
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
        cout<<mergeSort(v)<<endl;
    }
}
