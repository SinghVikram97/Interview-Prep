https://drive.google.com/open?id=1dB4qqWKd3xXkb9ZytpZ8y_eeodyXnUFu
https://drive.google.com/open?id=1g1tAwrTw4H9Dndm-KZvVN359B4NYhPNe

https://ide.geeksforgeeks.org/eeR5YS5yAN  (See binary_search function)

Lower bound: first element that is greater-or-equal.

Upper bound: first element that is strictly greater.

Total occurence of element=UpperBound-LowerBound

#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> v,int target){
    
   auto it=lower_bound(v.begin(),v.end(),target);
   
   int position=it-v.begin();
   
   return position;

    
}
int upperBound(vector<int> v,int target){
    
    auto it=upper_bound(v.begin(),v.end(),target);
    
    int position=it-v.begin();
    
    return position;
}
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        int target;
        cin>>target;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int lb=lowerBound(v,target);
        int ub=upperBound(v,target);
        
        // Binary Search to find if element exists
        if(binary_search(v.begin(),v.end(),target)){
            
            cout<<lb<<" "<<ub-1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
