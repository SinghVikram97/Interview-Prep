https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0

https://drive.google.com/open?id=13tkq9Hsxh53MgkigaOj5h27AqQJtqYFj

bool zeroSum(vector<int> &v,int n){
    
    unordered_set<int> previouslySeenSum;
    previouslySeenSum.insert(0); // For prefix sum ex. [1,-1]  at -1
    // sum=0 as we have previously seen it when array empty
    int sum=0;
    for(int i=0;i<n;i++){
        
        // Add current element to sum
        sum=sum+v[i];
        
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
