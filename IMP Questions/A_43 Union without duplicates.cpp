https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0

void unionF(vector<int> &nums1, vector<int> &nums2) {
            vector<int> ans;
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end());
            int i=0,j=0;
            int n1=nums1.size();
            int n2=nums2.size();
            while(i<n1 && j<n2){
                if(nums1[i]>nums2[j]){
                    ans.push_back(nums2[j]); // Can't find nums2[j] in array1 as it is greater
                    j++;
                }
                else if(nums2[j]>nums1[i]){
                    ans.push_back(nums1[i]);
                    i++;
                }
                else{                
                     ans.push_back(nums1[i]);
                     i++;
                     j++;
                }
            }
           while(i<n1){
               ans.push_back(nums1[i]);
               i++;
           }
           while(j<n2){
               ans.push_back(nums2[j]);
               j++;
           }
         for(int i=0;i<ans.size();i++){
             cout<<ans[i]<<" ";
         }
         cout<<endl;
}
