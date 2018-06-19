https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

https://drive.google.com/open?id=1y1upgWSjnRfjVE30PZ_7bQ_iMWSAFV5O O(n2)

#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n,sum;
        cin>>n>>sum;
        // 1 based indexing
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        
        vector<int> prefix(n+1);
        // Important
        prefix[0]=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+v[i];
        }
        
        
        int cs;
        bool found=false;
        int s,e;
        for(int i=1;i<=n;i++){
            
            for(int j=i;j<=n;j++){
                
                // Calculate sum b/w subarray i to j
                cs=prefix[j]-prefix[i-1];
                if(cs==sum){
                    found=true;
                    s=i;
                    e=j;
                    break;
                }
                
            }
            if(found){
                break;
            }
        }
       if(found){
           cout<<s<<" "<<e<<endl;
       }
       else{
           cout<<-1<<endl;
       }
    }
}
