int binarySearch(vector<int> &v,int data){

    if(v.size()==0){
    
        return -1; /// List is empty
    
    }

    int start=0,mid,end=v.size()-1;
    
    while(start<=end){
    
        mid=(start+end)/2;
        
        if(v[mid]==data){
        
            return mid;
        
        }
        
        else if(data<v[mid]){
        
        
            /// Move left
            end=mid-1;
        
        }
        else{
        
            /// Move right
            start=mid+1;
        
        }
    
    }
    return -1;
}
