https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x/0

// Same as finding pairs with sum < x just fix i and then find pair with sum<x-v[i] in remaining array

int countTriplets(vector<int> &v,int n,int x){
    
    int count=0;
    
    // Sort the array
    sort(v.begin(),v.end());
    
    // IMP i till n-3 only as last 3 elements are [n-3 n-2 n-1]
    for(int i=0;i<=(n-3);i++){
        
        int left=i+1;
        int right=n-1;
        
        int target_sum=x-v[i];
        
        
        while(left<right){
            
            if(v[left]+v[right]>=target_sum){
                right--;
            }
            else{
                count+=(right-left);
                left++;
            }
        }
    }
    return count;
}
