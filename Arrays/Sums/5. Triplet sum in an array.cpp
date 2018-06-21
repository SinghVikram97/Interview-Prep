https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0/


https://drive.google.com/open?id=10ApqxspulGalxtrMz3r3SYvvumaba-Mh  (Correction both method works for negative nos)

bool triplet(vector<int> v,int n,int required_sum){
    
    
    // Sort
    sort(v.begin(),v.end());
    

    // i till n-3 as after that there would be no triplets
    for(int i=0;i<=n-3;i++){
        
        // Select v[i] and now find pair that sums to k-v[i] in sorted array
        
        // We have to find that sum in array from [i+1,n-1]
        
        int j=i+1;
        int k=n-1;
        
        int target=required_sum-v[i];
        int sum;
        
        
        while(j<k){
            
            sum=v[j]+v[k];
            if(sum==target){
                return true;
            }
            else if(sum<target){
                j++;
            }
            else{
                k--;
            }
        }
    }
    return false;
}
