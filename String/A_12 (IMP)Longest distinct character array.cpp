https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

https://drive.google.com/open?id=1GHWeW7Vp66bwku8V4YL0YnTFeR4RUi2K
https://drive.google.com/open?id=1f8u3rBpkGUKnX3-PAGLSrchcjE88u6hI

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> st;
        /// Windows from [start,end) i=start and j=end
        int i=0,j=0; /// Intially window from [0,0) so no element included 
        int maxCount=0;
        while(i<n && j<n){
            // If element doesn't exist in current substring/window
            if(st.find(s[j])==st.end()){
                // Move window to the right ie. include j in window
                st.insert(s[j]);
                // Test next element
                j++;
                // Update length
                maxCount=max(maxCount,j-i);  // Current window is [i,j)
            }
            else{
                // Keep removing elements from start till end element ie. s[j] can be added to window/substring
                st.erase(s[i]);
                // Increase the start
                i++;
            }
        }
        return maxCount;
    }
};

CAN BE OPTIMIZED FURTHER SEE SOLUTION IN LEETCODE. JUST MOVE TO MAX(LAST POSITION OF DUPLICATE ELEMENT+1,I)
abba
we need max
