https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/1

PRINT ALL OCCURENCES AS IT IS

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            vector<int> ans;
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end());
            int i=0,j=0;
            int n1=nums1.size();
            int n2=nums2.size();
            while(i<n1 && j<n2){
                if(nums1[i]>nums2[j]){
                    j++;
                }
                else if(nums2[j]>nums1[i]){
                    i++;
                }
                else{                
                     ans.push_back(nums1[i]);
                     i++;
                     j++;
                }
            }
         return ans;
    }
