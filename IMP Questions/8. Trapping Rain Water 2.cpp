https://leetcode.com/problems/trapping-rain-water/description/

https://drive.google.com/open?id=1hWAnrYDEDKkPJW0jFiOEvZSm6XNXSlnU (IMP)
https://leetcode.com/problems/trapping-rain-water/solution/ (IMP)

https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c%2B%2B-code%3A-O(n)-time-O(1)-space (Check comments)


class Solution {
public:
    int trap(vector<int> &height) {
        
        int n=height.size();
        
        int max_left=0;  // As 0 is the least height possible
        int max_right=0;
        
        int left=0;
        int right=n-1;
        
        int ans=0;
        
        while(left<=right){
            
            // It means a greater building on the right exists so depends only of left_max
            if(height[left]<height[right]){
                
                // It means covered by max_left from left side
                if(height[left]<max_left){
                    ans=ans+(max_left-height[left]);  
                }
                // Not covered from left so update max_left
                else{
                    max_left=height[left];
                }
                left++;                
            }
            // height[right]<height[left]
            // It means a greater building on the left exists
            else{
                
                if(height[right]<max_right){
                    ans=ans+(max_right-height[right]);
                }
                else{
                    max_right=height[right];
                }
                right--;                
            }
        }
        return ans;       
        
    }
};
