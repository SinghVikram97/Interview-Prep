https://leetcode.com/problems/single-number-ii/

https://drive.google.com/open?id=1OmXbbOD14TU85xrZfem1Asj_oE1NxqCT (BRUTE FORCE)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        
        for(int i=0;i<nums.size();i++){
            
            freq[nums[i]]++;
            
        }
        
        for(auto it=freq.begin();it!=freq.end();it++){
            if(it->second==1){
                return it->first;
            }
        }
        
    }
};


https://drive.google.com/open?id=1ZhhXD_eJ5ujz6gweP005Ot9WBT1jzg-T
https://drive.google.com/open?id=16StSvArDRj85EJKtANL36gq5aWfccXKP

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        
        // How many times to repeat? Assume numbers to be 32 bit so repeat 32 times 
        int number=0;
        
        
        
        for(int i=0;i<32;i++){
            
                        
            bool sareZero=true;  // Stop if all numbers become zero
            
            int sum=0;
            
            // At each step extract the last bit(rightmost) and right shift the current number
            for(int j=0;j<nums.size();j++){
                
                if(nums[j]!=0){
                    sareZero=false;
                }
                
                sum=sum+(nums[j]&1);  // Extract right most bit
                nums[j]=nums[j]>>1;   // Right shift by one
                
            }   
            sum=sum%3; 
            
            
            // This sum is the ith bit so shift it left by i time
            sum=sum<<i;
            
            // Take OR with the num
            number=number|sum;
            
            if(sareZero){
                return number;
            }
        }         
        return number;
    }
};
