https://practice.geeksforgeeks.org/problems/consecutive-array-elements/0

https://drive.google.com/open?id=1FPEjovhzccRfKP9js4InkmneN1ZfmD9Q

VISITED ARRAY
--------------------------------------------
bool consecutive(vector<int> &v){
    
    int n=v.size();
    
    int maX=INT_MIN;
    int miN=INT_MAX;
    
    for(int i=0;i<n;i++){
        maX=max(maX,v[i]);
        miN=min(miN,v[i]);
    }
    
    if(maX-miN+1==n){
        
        // No need of visited array is we are given distinct elements
        vector<bool> visited(n);
        
        for(int i=0;i<n;i++){
            
            // If element has been visited before
            if(visited[v[i]-miN]==true){
                return false;
            }
            
            // Else set it to true
            else{
                visited[v[i]-miN]=true;
            }
        }
        // All elements visited once(no duplicates) and max-min+1=n so consecutive elements
        return true;
    }
    else{
        return false;
    }
}

https://drive.google.com/open?id=16h8seE_aamZ_-fRfBa32t-hN7yb1VTyF
AP
......................................
bool consecutive(vector<int> &v){
    
    int n=v.size();
    
    int maX=INT_MIN;
    int miN=INT_MAX;
    
    int totalSum=0;
    int expectedSum=0;
    
    for(int i=0;i<n;i++){
        maX=max(maX,v[i]);
        miN=min(miN,v[i]);
        totalSum+=v[i];
    }
    
    if(maX-miN+1==n){
        
        expectedSum=(n*(miN+maX))/2;
        if(totalSum==expectedSum){
            return true;
        }
        else{
            return false;
        }
        
    }
    else{
        return false;
    }
}

https://drive.google.com/open?id=1kHOVkjiEus1BN_5v_knarUbmvk8am8kv
XOR
.......................................
bool consecutive(vector<int> &v){
    
    int n=v.size();
    
    int maX=INT_MIN;
    int miN=INT_MAX;
    
    int allXor=0;
    
    for(int i=0;i<n;i++){
        maX=max(maX,v[i]);
        miN=min(miN,v[i]);
        allXor=allXor^(v[i]);
    }
    
    if(maX-miN+1==n){
        
        for(int i=miN;i<=maX;i++){
            allXor=allXor^(i);
        }
        if(allXor==0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
