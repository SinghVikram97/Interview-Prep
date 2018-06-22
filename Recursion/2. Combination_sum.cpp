https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0

https://drive.google.com/open?id=1qRkBl3Ie8XC9nnZwu9PaZWmWZXZZxXrB
https://drive.google.com/open?id=1lAgcG6CWHpf-rya8lrb4y6Yh_A6FSldk

#include<bits/stdc++.h>
using namespace std;
void combination_sum(vector<int> &v,int i,int sum,vector<int> ans){
    
    if(sum==0){
        cout<<"(";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<")";
    }
    else{
        
        // Current element has 2 choices it can be in the combination or not
        
        // We can take current element only if it is <= to given sum
        if(v[i]<=sum){
            
            // Take it
            ans.push_back(v[i]);
            
            // Find combinations with sum-v[i]
            combination_sum(v,i+1,sum-v[i],ans);
            
            // Don't take 
            // 1st backtrack
            ans.pop_back();
            
            combination_sum(v,i+1,sum,ans);
        }
        // If current element greater than sum then all elements ahead of it also greater
        // As array sorted so return
        else{
            return;
        }
    }
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
        int sum;
        cin>>sum;
        // sort the original array
        sort(v.begin(),v.end());
        vector<int> ans;
        combination_sum(v,0,sum,ans);
        cout<<endl;
    }
}
