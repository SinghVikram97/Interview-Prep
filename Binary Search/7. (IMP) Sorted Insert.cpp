We can just return the start or low if element not found why?
https://discuss.leetcode.com/uploads/files/1491338332712-capture-d-%C3%A9cran-2017-04-04-%C3%A0-16.38.21.png


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        
        int n=nums.size();
        
        int start=0,end=n-1;
        int mid;
        
        while(start<=end){
            
            mid=(start+end)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(target<nums[mid]){
                // Move left
                end=mid-1;
            }
            else{
                // Move right
                start=mid+1;
            }
        }
        return start;
    }
};
