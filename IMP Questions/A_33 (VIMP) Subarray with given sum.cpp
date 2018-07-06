https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

SINCE IT ONLY CONTAINS POSITIVE ELEMENT SO IT IS A HINT TO USE SLIDING WINDOW APPROACH

https://drive.google.com/open?id=1MYWYhViVm_OTTxe1bCw2L-ZL80eWiY44

pair<int,int> solve(vector<int> &v,int n,int target){
    
    // Window contains the 1st element only
    int current_sum=v[0];
    int start=0;
    int end=0;
    while(end<n){
       
       // If current_sum smaller than target
       if(current_sum<target){
           // Move end pointer forward to increase sum
           end++;
           current_sum+=v[end];
       }
       
       // If current_sum equal to target
       else if(current_sum==target){
           return make_pair(start,end);
       }
       
       // current_sum is greater than target and start<end
       // If start=end and we increment start by one
       // start will become > end so check that
       
       else if(current_sum>target && start<end){
           // Remove elements from start
           current_sum-=v[start];
           start++;
       }
       // Both start and end equal and current_sum>target
       // So subtract the element from currentSum
       // And add next element to currentSum
       // ex1. 1 5 2 0 and k=2 or 0
       // ex2. 5 2 and k=2
       else{
           current_sum-=v[start];
           start++;
           end++;
           current_sum+=v[start];
       }
    }
    return make_pair(-1,-1);
}
