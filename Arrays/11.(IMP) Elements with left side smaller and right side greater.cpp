https://practice.geeksforgeeks.org/problems/unsorted-array/0

https://drive.google.com/open?id=18_j-WitOifbMKPZ7YrQu7dL0TQ6J3V5U

int element(vector<int> &v,int n){
    
    vector<int> max_left(n);
    vector<int> min_right(n);
    
    int maximum=INT_MIN;
    
    // 0 and n-1 can't be the answer
    
    for(int i=1;i<=n-2;i++){
        maximum=max(maximum,v[i-1]);
        max_left[i]=maximum;
    }
    
    int minimum=INT_MAX;
    for(int i=n-2;i>=1;i--){
        minimum=min(minimum,v[i+1]);
        min_right[i]=minimum;
    }
    
    for(int i=1;i<=n-2;i++){
        if(v[i]>=max_left[i] && v[i]<=min_right[i]){
            return v[i];
        }
    }
    return -1;
}
