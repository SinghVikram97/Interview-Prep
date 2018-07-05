

...........................................
BRUTE FORCE - O(N2)
int subarraySum(vector<int>& v, int k) {
        
        int n=v.size();
        int count=0;
        int sum;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum=sum+v[j];
                if(sum==k){
                    // Subarray b/w i to j
                    cout<<i<<" "<<j<<endl;
                    count++;
                }
            }
        }
        return count;
   }
   
   
..........................................
USING PREFIX SUM
TIME-O(n2) Space-O(n2)

https://drive.google.com/open?id=1IGPQaonmcwqpggJHieWUWB_vsQxwaDYR

int subarraySum(vector<int>& v, int k) {
        
        int n=v.size();
        vector<int> prefixSum(n+1);  // prefixSum[i] represents sum upto i-1th index
        prefixSum[0]=0;
        for(int i=1;i<=n;i++){
            prefixSum[i]=prefixSum[i-1]+v[i-1];
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // subarray [i........j]
                // Sum upto j-sum upto i-1
                if(prefixSum[j+1]-prefixSum[i]==k){
                    count++;
                }
            }
        }
        return count;
 }
 
 ...........................................
 Optimized solution using map
 TIME-O(n) Space-O(n)  Hashmap map can contain upto n distinct entries in the worst case
 https://drive.google.com/open?id=1JdrnmTKkArV-fqo9D0Rt2kTez0oVIEfA (IMP)
 https://drive.google.com/open?id=13tkq9Hsxh53MgkigaOj5h27AqQJtqYFj (IMP)
 
 int subarraySum(vector<int>& v, int k) {
        
        int n=v.size();
        int currentSum=0;
        int count=0;
        unordered_map<int,int> previousSums;  // Maps previous sums upto given index to their frequency
        previousSums.insert(make_pair(0,1));  // Empty array also a subarray with 0 sum
        
            
        for(int j=0;j<n;j++){
            currentSum+=v[j];  // Sum of v[0.....j]
            
            // Sum of v[i.....j]=Sum of v[0......j]-Sum of v[0....i-1]
            // k=Sum of v[0......j]-Sum of v[0....i-1]
            // Sum of v[0.....i-1]=Sum of v[0......j]-k
            
           // So find number of previous sums with SUM=sum-k
            if(previousSums.find(currentSum-k)!=previousSums.end()){
                count+=previousSums[currentSum-k];
            }
            
            // Add this sum to map
            previousSums[currentSum]++;           
        }
        return count;
    }
