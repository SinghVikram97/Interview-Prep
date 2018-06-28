https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        int start=0,end=n-1,mid;
        
        
        while(start<=end){
            
            // 1. Calculate mid
            mid=(start+end)/2;
            
            
            // 2. If mid is equal to element
            if(nums[mid]==target){
                return mid;
            }
            
            // 3. See if array is rotated or not
            if(nums[end]>nums[start]){
                
                // Not rotated so simple binary search
                
                if(target<nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            
            // 4. If rotated mid will divide array into 2 parts
            // One is sorted and other not sorted
            // We can easily see if target in sorted array or not
            
            
            else if(nums[mid]<nums[start]){
                
                // Left unsorted so right is sorted
                
                // Find if element in right sorted part
                
                if(target>nums[mid] && target<=nums[end]){
                    
                    // Move right
                    start=mid+1;
    
                }
                else{
                    
                    // Move left
                    end=mid-1;
                }
                
            }
            
            else{
                // Right unsorted so left sorted
                
                // Find if element in left sorted part
                
                if(target>=nums[start] && target<nums[mid]){
                    // Move left
                    end=mid-1;
                }
                else{
                    // Move right
                    start=mid+1;                    
                }
            }           
        }
        return -1; // Element not found
    }
};
