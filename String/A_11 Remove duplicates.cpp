https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

int removeDuplicates(vector<int>& nums) {
        
        int pos=-1;  // Position of last element that is distinct
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[pos]){
                pos++;
                nums[pos]=nums[i];
            }
        }
        // return pos+1; // Since array 0 based so length=lastIndex+1
        nums.erase(nums.begin()+pos+1,nums.end());
        return nums.size();
}


/// If not sorted and we want to maintain order
https://practice.geeksforgeeks.org/problems/remove-duplicates/0/

void removeDuplicates(string &s){
    
    unordered_map<char,int> freq;
    int n=s.length();
    string ans="";
    for(int i=0;i<n;i++){
        if(freq[s[i]]==0){
            freq[s[i]]++;
        }
    }
    
    for(int i=0;i<n;i++){
        if(freq[s[i]]==1){
            //cout<<s[i];
            ans=ans+s[i];
            freq[s[i]]--;
        }
    }
    s=ans;
}
