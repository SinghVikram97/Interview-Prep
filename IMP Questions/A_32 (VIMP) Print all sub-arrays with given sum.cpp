TEST CASE-[1,1,1] K=2
https://leetcode.com/problems/subarray-sum-equals-k/description/
....................................................................
BRUTE FORCE-O(N2)

int subarraySum(vector<int>& v, int k) {
        
        int n=v.size();
        int count=0;
        int sum;
        for(int i=0;i<n;i++){
            sum=0;
            // IMP START FROM I AS [i..i] also a subaray with single element
            for(int j=i;j<n;j++){
                sum=sum+v[j];
                if(sum==k){
                    cout<<i<<" "<<j<<endl;
                    count++;
                }
            }
        }
        return count;
    }
.......................................................................
https://drive.google.com/open?id=1RfP5WrQk5ZiHXpPtZjUlfSsHn-EE6EVE
https://drive.google.com/open?id=1vXsHwSijU2nTOxams4fuoSCkWWtOm_9Y

WORST CASE TIME->O(N2) 
SPACE COMPLEXITY-> O(N) AS WE ARE STORING SUM FROM O UPTO I
AND I CAN VARY FROM 0 TO N 

int subarraySum(vector<int>& v, int k) {
        
        int n=v.size();
        unordered_map<int,vector<int> > previousSum; // Stores the last index of subarray ending with given sum
        previousSum[0].push_back(-1);  // Empty subarray for prefix sum
        int currentSum=0;
        
        for(int i=0;i<n;i++){
            currentSum+=v[i];
            
            if(previousSum.find(currentSum-k)!=previousSum.end()){
                
                // Subarray with given sum exists b/w (last index of previousSum[curSum-k])+1 and i
                for(auto it=previousSum[currentSum-k].begin();it!=previousSum[currentSum-k].end();it++){
                    cout<<(*it)+1<<" "<<i<<endl;
                }
                
            }
            
            //Add this currentSum with last index as i
            previousSum[currentSum].push_back(i);
        }
        return 0;
    }
