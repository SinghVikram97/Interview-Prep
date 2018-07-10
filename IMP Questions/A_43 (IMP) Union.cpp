https://ide.geeksforgeeks.org/KzdzvesRf6

void unionF(vector<int> &nums1, vector<int> &nums2) {
            vector<int> ans;
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end());
            int i=0,j=0;
            int n1=nums1.size();
            int n2=nums2.size();
            while(i<n1 && j<n2){
                if(nums1[i]>nums2[j]){
                    if(ans.size()>0 && ans.back()==nums2[j]){
                         // Duplicate
                     }
                     else{
                         ans.push_back(nums2[j]);
                     }
                    j++;
                }
                else if(nums2[j]>nums1[i]){
                    if(ans.size()>0 && ans.back()==nums1[i]){
                         // Duplicate
                     }
                     else{
                         ans.push_back(nums1[i]);
                     }
                    i++;
                }
                else{              
                     if(ans.size()>0 && ans.back()==nums1[i]){
                         // Duplicate
                     }
                     else{
                         ans.push_back(nums1[i]);
                     }
    
                     i++;
                     j++;
                }
            }
           while(i<n1){
               if(ans.size()>0 && ans.back()==nums1[i]){
                         // Duplicate
                     }
                     else{
                         ans.push_back(nums1[i]);
                     }
               i++;
           }
           while(j<n2){
               if(ans.size()>0 && ans.back()==nums2[j]){
                         // Duplicate
                     }
                     else{
                         ans.push_back(nums2[j]);
                     }
               j++;
           }
         for(int i=0;i<ans.size();i++){
             cout<<ans[i]<<" ";
         }
         cout<<endl;
}
