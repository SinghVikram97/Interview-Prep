https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

IF IT INCLUDES NEGATIVE NUMBERS ALSO

pair<int,int> solve(vector<int> &v,int n,int target){
    
    // NO NEED TO STORE PREVIOUS INDEXES IN A VECTOR
    // SINCE WE NEED ONLY ONE SUBARRAY WITH GIVEN SUM
    
    map<int,int> previousSum;  // Maps sum of previous subarray to it's last index
    previousSum.insert(make_pair(0,-1)); // Empty subarray with 0 sum
    
    int currentSum=0;
    for(int i=0;i<n;i++){
        currentSum+=v[i];
        if(previousSum.find(currentSum-target)!=previousSum.end()){
            return make_pair(previousSum[currentSum-target]+1,i);
        }
        previousSum.insert(make_pair(currentSum,i));
    }
    return make_pair(-1,-1);
    
}
