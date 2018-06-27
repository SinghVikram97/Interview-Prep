https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0

https://drive.google.com/open?id=1Ij70qnKLgO5oVknXT6UseTZbcJ8ax7Ho

int lowerBound(vector<int> v,int target){
    
    int n=v.size();
    
    int start=0,mid,end=n-1;
    
    int lB=-1; // Returns -1 if element not found
    
    while(start<=end){
        
        mid=(start+end)/2;
        
        if(v[mid]==target){
            
            // Store the position
            lB=mid;
            // Move further left to explore more
            end=mid-1;
        }
        else if(target<v[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return lB;
}
int upperBound(vector<int> v,int target){
    
     int n=v.size();
     
     int start=0,mid,end=n-1;
     
     int uB=-1;  // Returns -1 if element not found
     
     while(start<=end){
         
         mid=(start+end)/2;
         
         if(v[mid]==target){
             
             // Store the position
             uB=mid;
             // Move further right to explore
             start=mid+1;
             
         }
         else if(target<v[mid]){
             end=mid-1;
         }
         else{
             start=mid+1;
         }
     }
    return uB;
}
