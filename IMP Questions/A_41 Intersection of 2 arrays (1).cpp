https://leetcode.com/problems/intersection-of-two-arrays/description/

https://drive.google.com/open?id=1-MK2DZ_oQHoFAWreugGwijsDVUi5xKdx (unordered_set)
https://drive.google.com/open?id=1KbEPbzlZ5WH3y7Aqs-MfLbVRjkYc8Ysl (Binary Search)
https://drive.google.com/open?id=1UkqinbA8FiRVsVuU3N5X_Vz2qBsAia3J (Sorting)

 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
                    // Already added that number
                    if(ans.size()>0 && ans.back()==nums1[i]){
                        // Duplicate don't add
                    }  
                    // Either ans is empty or haven't added that no
                    else{
                        ans.push_back(nums1[i]);
                    }
                     i++;
                     j++;
                }
            }
         return ans;
    }
