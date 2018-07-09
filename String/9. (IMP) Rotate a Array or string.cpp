https://leetcode.com/problems/rotate-array/description/

O(N) SPACE--> https://drive.google.com/open?id=1cTBSPixVTE4etH4PIFG-8aqONdRkP6cm
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         
        int n=nums.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[(i+k)%n]=nums[i];
        }
        nums=temp;        
    }
};


O(1) SPACE--> https://drive.google.com/open?id=1S_A4BbciCUwzVgGBMxIFJPQXO-8TsIwB

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        k=k%n;  // Incase k>n 
        reverse(nums.begin(),nums.end());
        // [front,last)
        reverse(nums.begin(),nums.begin()+(k));
        reverse(nums.begin()+(k),nums.end());
    }
};
