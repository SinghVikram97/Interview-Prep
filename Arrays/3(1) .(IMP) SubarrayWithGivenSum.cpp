https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

O(n2)
    
#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n,target;
        cin>>n>>target;
        
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        
        int sum;
        int start,end;
        bool found=false;
        
        for(int i=1;i<=n;i++){
            
            sum=0;
            
            // Explore all subarrays starting with i
            
            for(int j=i;j<=n;j++){
                
                // Subarray from i to j
                
                sum=sum+v[j];
                if(sum==target){
                    found=true;
                    start=i;
                    end=j;
                    break;
                }
                
            }
            if(found){
                break;
            }
        }
        if(found){
            cout<<start<<" "<<end<<endl;
        }       
        else{
            cout<<-1<<endl;
        }
    }
}
