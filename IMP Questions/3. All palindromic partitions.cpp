https://leetcode.com/problems/palindrome-partitioning/submissions/1

https://drive.google.com/open?id=1r1lpaJKsmZ2RCWO2viVRLp_pAV4WlSsX

class Solution {
public:
    
    bool isPalindrome(string &s,int start,int i){
        
        int end=i;
        
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void allPalindromes(string &s,int start,vector<string> path,vector<vector<string> > &finalAns){
        
        if(start==s.length()){
            finalAns.push_back(path);
            return;
        }
        
        // Pick all possible ending points from start till end
        for(int i=start;i<s.length();i++){
            
            // Check if palindrome from start till i
            if(isPalindrome(s,start,i)){
                
                // Push into path from start till i (length=i-start+1)
                path.push_back(s.substr(start,i-start+1));
                
                // Generate palindromes for remaining string starting from i+1
                allPalindromes(s,i+1,path,finalAns);
                
                // Backtrack
                path.pop_back();                   
            }
            
        }
        // If no possible palindromes from start to n it returns from here and never gets to the base case
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string> > finalAns;
        vector<string> path;
        
        allPalindromes(s,0,path,finalAns);  
        
        return finalAns;
        
        
    }
};
