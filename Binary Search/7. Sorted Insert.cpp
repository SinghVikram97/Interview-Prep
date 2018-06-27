https://leetcode.com/problems/search-insert-position/description/

https://drive.google.com/open?id=1sQUr_AXnv9pOZBSmGzpO_l0t9nVAF_p-

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       
        
        int n=nums.size();
        
        /// If target>last element ie.  greatest element in array return n
        if(target>nums[n-1]){
            return n;
        }
        
        
        // Else find the next greatest element or the element itself
        int start=0,end=n-1,mid;
        int pos;
        
        while(start<=end){
            
            mid=(start+end)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                
                // This element greater so this can be a potential ans store it
                pos=mid;
                // Move left
                end=mid-1;
                
            }
            else{
                start=mid+1;
            }
        }
        return pos;       
    }
};
