https://leetcode.com/problems/single-number-iii/description/

https://drive.google.com/open?id=1YA_clDvRxy5o3DnZ5h-Nu_yQBD9Jkd5F
https://drive.google.com/open?id=1rrn0eHF8ooS5MwOzwvj6G15wGxRLEtAQ
https://drive.google.com/open?id=1xWq1ru4hmBgeIFHm50qcosRYhvOnnUXL  (VIMP)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        
        // 1. XOR all elements
        int xorAll=0;
        
        for(int i=0;i<nums.size();i++){
            xorAll=(xorAll^nums[i]);
        }
        
        // 2. Find a set bit for that xor (If a bit is set in xor it means the 2 elements have different bits at that position)
        // We can offset rightmost set bit of a number n by doing n&(n-1)
        // So to get a number will all bits 0 and only rightmost bit of n as 1 we do n&(~(n-1))
        
        int bit=xorAll&(~(xorAll-1));
        
        // Now divide numbers into 2 groups one which has that bit set and other which does not 
        // Our 2 numbers will lie in different groups
        
        int number1=0,number2=0;
                 
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]&bit){
                number1=number1^nums[i];
            }
            else{
                number2=number2^nums[i];
            }
        }
        
        return {number1,number2};
        
    }
};
