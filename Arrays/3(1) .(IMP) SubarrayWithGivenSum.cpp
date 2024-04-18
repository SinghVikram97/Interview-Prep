https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

O(n2)
    
#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n,target;
        cin>>n>>target;
        
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        
        int sum;
        int start,end;
        bool found=false;
        
        for(int i=1;i<=n;i++){
            
            sum=0;
            
            // Explore all subarrays starting with i
            
            for(int j=i;j<=n;j++){
                
                // Subarray from i to j
                
                sum=sum+v[j];
                if(sum==target){
                    found=true;
                    start=i;
                    end=j;
                    break;
                }
                
            }
            if(found){
                break;
            }
        }
        if(found){
            cout<<start<<" "<<end<<endl;
        }       
        else{
            cout<<-1<<endl;
        }
    }
}

// https://leetcode.com/problems/subarray-sum-equals-k/description/
// O(N)
// [a,b,c,d,e]

// SubarraySum(c...d)=CurrentSum(a...d)-previousSubrraySum(a..b)

// TargetSum = CurrentSum - previousSubarraySum

// previouSubarraySum = CurrentSum - targetSum

// So we store frequency of how many times we have seen this previousSubarraySum

// Add (0,1) for full subarray

// ie. [1,2,3],,, 6-0(empty array)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // freq map to store freq of currentSum encountered till now
        unordered_map<int,int> myMap;
        myMap[0]=1;

        int currentSum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            currentSum+=nums[i];
            ans+=myMap[currentSum-k];
            myMap[currentSum]++;
        }
        return ans;
    }
};
