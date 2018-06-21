
bool findPair(vector<int> &v,int n,int k){
    
    sort(v.begin(),v.end());
    
    // Start and end
    int l=0,r=n-1;
       
    // Not l=r
    while(l<r){
        
        if(v[l]+v[r]==k){
            return true;
        }
        else if(v[l]+v[r]<k){
            l++;
        }
        else{
            r--;
        }
    }
    
    return false;
}
