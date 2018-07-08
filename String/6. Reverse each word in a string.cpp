https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string/0

// Time is O(N) if we neglect the time to reverse

void reverseEachWord(string &s){
    int start=0; // Initally word starting from 0
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            // Reverse from start till position of '.'-1
            // Reverse function reverses from [first,last) so i
            reverse(s.begin()+start,s.begin()+i);
            start=i+1;
        }
    }
    reverse(s.begin()+start,s.end()); // For last word
}

// Another approach
void reverseEachWord(string &s) {
    
    string currentString="";
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='.'){
            currentString+=s[i]; /// For space
            ans+=currentString;
            currentString="";
        }
        else{
            currentString=s[i]+currentString; /// Reverse so
        }
    }
    ans+=currentString;
    s=ans;
}
