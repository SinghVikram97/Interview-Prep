https://practice.geeksforgeeks.org/problems/four-elements/0

https://drive.google.com/open?id=1D0gkvfK0PjSQbMu-tRInbbRf9HZvW87X
https://drive.google.com/open?id=1SAM1HEGXcWxfirhPeZ525cAG5f4JVP1Z
https://drive.google.com/open?id=1O7vof7AfJ6ERcbxdvTt8oc1QwsSgZ_6W
https://drive.google.com/open?id=18_lnx3Lxu7J81xmUhgn1kDn5gnWTdp5S
https://drive.google.com/open?id=1697KKMcgCKEoQ8D-HvMkquQX1-rl0N3B

struct pairSum{
    
    int sum;
    int first;
    int second;
    
};
bool comp(pairSum &a,pairSum&b){
    
    if(a.sum<=b.sum){
        return true;
    }
    else{
        return false;
    }
    
}
bool noCommon(pairSum a,pairSum b){
    
    if(a.first==b.first || a.first==b.second || a.second==b.first || a.second==b.second){
        return false;
    }
    return true;
}
bool fourSum(vector<int> &v,int n,int x){
    
    // Create an array of struct of size n*(n-1)/2
    int size=(n*(n-1))/2;
    
    pairSum arr[size];
    
    // Store sum of all pairs along with their indices in this array
    int k=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            
            arr[k].sum=v[i]+v[j];
            arr[k].first=i;
            arr[k].second=j;
            k++;
        }
    }
    
    // Sort this array of pair sum
    sort(arr,arr+size,comp);
    

    // for(int i=0;i<size;i++){
    //     cout<<arr[i].sum<<" "<<arr[i].first<<" "<<arr[i].second<<endl;
    // }
   
   
    // Find a pair with given sum in this array of pair sum
    int left=0,right=size-1;
    
    while(left<right){
        
        if(arr[left].sum+arr[right].sum==x){
            
            //cout<<arr[left].first<<" "<<arr[left].second<<" "<<arr[right].first<<" "<<arr[right].second<<endl;
            if(noCommon(arr[left],arr[right])){
                return true;
            }
            else{
                right--;
            }
        }
        else if(arr[left].sum+arr[right].sum<x){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
}
