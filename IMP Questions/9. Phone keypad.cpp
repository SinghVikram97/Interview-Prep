https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    void backtrack(string &digits,int index,unordered_map<int,string> &myMap,string path,vector<string> &finalAns){
        
        // Base case
        if(path.size()==digits.size()){
            finalAns.push_back(path);
        }
        
        // For given index take all possible letters in digit[index] one by one
        int num=digits[index]-'0';  // Typecase '1' to 1
        
        // Traverse string represented by that num one by one ex 2-->"abc"
        
        // myMap[num] is a string 
        string s=myMap[num];
        
        // Traverse the string
        for(int i=0;i<s.length();i++){
            
            // Add current character to path
            path.push_back(s[i]);
            
            // Find possible strings for next number
            backtrack(digits,index+1,myMap,path,finalAns);
            
            // Backtrack and try different character
            path.pop_back();
            
        }       
        
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0){
            return {}; // Returning empty string not {""}
        }
        
        // Build a map from int to string
        unordered_map<int,string> myMap;
        myMap[2]="abc";
        myMap[3]="def";
        myMap[4]="ghi";
        myMap[5]="jkl";
        myMap[6]="mno";
        myMap[7]="pqrs";
        myMap[8]="tuv";
        myMap[9]="wxyz";
        
        vector<string> finalAns;
        string path;
        
        backtrack(digits,0,myMap,path,finalAns);
        
        return finalAns;
    }
};
