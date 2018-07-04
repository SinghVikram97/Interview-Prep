https://leetcode.com/problems/move-zeroes/description/

Test Cases- 0 1 0 12 3 0
            1 0 0 1

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n=nums.size();
        
        int lastFoundNonZero=-1; // Like quick sort
        
        // Bring all non zero elements to the front
        // Keeping order same
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                lastFoundNonZero++;
                nums[lastFoundNonZero]=nums[i];
            }
        }
        
        // Now fill all zeroes from lastFoundNonZero+1 to n
        for(int i=lastFoundNonZero+1;i<n;i++){
            nums[i]=0;
        }
    }
};
