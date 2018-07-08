https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

https://drive.google.com/open?id=1xmIb7jA5ZVUYqE7Do8RMbhzltl-bPa01

void reverseWords(string &s) {
        /// 1.Reverse the whole string
        reverse(s.begin(),s.end());
        /// 2. Reverse indiviual words
        int start=0,end;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                /// Reverse from start to till position of dot-1
                /// Reverse function reverses from [start,end)
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
            }
        }
        /// For last word
        reverse(s.begin()+start,s.end());
}

void reverseWords(string &s) {

    int n=s.length();
    string currentString="";
    string ans="";
    for(int i=n-1;i>=0;i--){
        if(s[i]==' '){
            currentString+=s[i];
            ans+=currentString;
            currentString="";
        }
        else{
            currentString=s[i]+currentString;  /// Imp not currentString+=s[i];
        }
    }
    ans+=currentString;
    s=ans;

}
