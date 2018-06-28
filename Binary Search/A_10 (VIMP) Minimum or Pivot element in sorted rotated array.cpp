https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

https://drive.google.com/open?id=1W5o4Ifmq_9VClfDJYV4TWPkuOjsv11-B
https://drive.google.com/open?id=1E4Dp3o7HtddYaQrtjf5vGrOIwEHAgupk
https://drive.google.com/open?id=1Ybry1Itrftkz8Q0yUiQg9Gasa9jVi2vY  (IMPPP)

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        
        int start=0,mid,end=n-1;
        
        // Gives no return value on [1] so check if single element array
        if(n==1){
            return nums[0];
        }
        
        while(start<=end){
                      
            // Check if array is rotated or not
            if(nums[end]>nums[start]){
                // Array not rotated return 1st element of the array
                return nums[start];
            }
            
            // Otherwise find mid
            mid=(start+end)/2;
            
            // If a number less than it's previous then it is minimum element
            if(mid-1>=0 && nums[mid]<nums[mid-1]){
                 return nums[mid];
            }
                        
            // Else mid divided array into 2 parts
            // nums[start....mid] && nums[mid....end]
            // One is sorted and one is not sorted
            // Minimum element lies in unsorted part
            
            // Left not sorted
            if(nums[mid]<nums[start]){
                
                // Move left
                end=mid-1;
                
            }
            // Right is not sorted ie. nums[end]<nums[mid]
            else{
                
                // Move right
                start=mid+1;
                
            }
        }
    }
};
