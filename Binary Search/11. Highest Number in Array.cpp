https://practice.geeksforgeeks.org/problems/find-the-highest-number/0

https://drive.google.com/open?id=1Wm134DVzRUp3yIAQLOy-oGsvFzLGN_s6

// 1 2 3 1 2 2 (No peak element)

int maxElement(vector<int> &v,int n){
    
    // Can't be a peak element for 1 or 2 elment array
    if(n<3){
        return v[n-1];
    }

    int start=0,mid,end=n-1;
    
    while(start<=end){
        
        mid=(start+end)/2;
        
        // v[mid-1] or v[mid+1] won't give segmentation fault because our peak element
        // Will lie at min index 1 and max index n-2 for it to be peak
        // We can add a condition to check if peak element exists or not
        if(mid-1<0 || mid+1>n){
            return -1;  /// For [1,2,3,4,5] or [5,4,3,2,1] mid will become 5
        }
        
        // If peak element return
        if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
            return v[mid];
        }
        // If series is increasing move right
        else if(v[mid]>v[mid-1] && v[mid]<v[mid+1]){
            start=mid+1;
        }
        // If series is decreasing move left
        else{
            end=mid-1;
        }
        
    }
    
}
