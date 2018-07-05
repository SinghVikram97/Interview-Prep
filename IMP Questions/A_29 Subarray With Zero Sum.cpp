https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0

https://drive.google.com/open?id=1o96XQjFUqC_C9X6RMPuPhvz-O5Fc5Usp

bool zeroSum(vector<int> &v,int n){
    
    unordered_set<int> previouslySeenSum;
    int sum=0;
    for(int i=0;i<n;i++){
        
        // Add current element to sum
        sum=sum+v[i];
        
        // Either prefix sum becomes zero ex. 1 -1 or 2 1 -1
        if(sum==0){
            return true;
        }
        
        // OR
        // If this sum was previously seen at some point then it means
        // A subarray with zero sum b/w these 2 points
        if(previouslySeenSum.find(sum)!=previouslySeenSum.end()){
            return true;
        }
        
        // Add this sum to previously seen sum
        previouslySeenSum.insert(sum);
    }
    return false;
    
}
