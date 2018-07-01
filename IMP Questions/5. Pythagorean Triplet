Similar approach as triplet sum

https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0

bool triplet(vector<int> &v,int n){
    
    // Replace numbers with it's squares in array
    for(int i=0;i<n;i++){
        v[i]=v[i]*v[i];
    }
    // Sort in decreasing order
    sort(v.begin(),v.end(),greater<int>());
    // As we need to fix element so 6,5,4,3,2,1
    // 5=4+3 so we fix 5 and explore 4 and 3
    // If we sort in increasing order
    // Then start from end
    for(int i=0;i<=n-3;i++){
        
        int start=i+1;
        int end=n-1;
        int target=v[i];
        
        while(start<=end){
            
            int sSquare=v[start];
            int eSquare=v[end];
            
            if(sSquare+eSquare==target){
                return true;
            }
            // As decreasing order so to increase the number 
            // Move left
            else if(sSquare+eSquare<target){
                end--;
            }
            // To decrease move right
            else{
                start++;
            }
            
        }
        
    }
    return false;
}
