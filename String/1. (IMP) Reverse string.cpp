string reverseString(string s){
    int start=0;
    int end=s.length()-1;
    /// No harm in putting = as character swapped with same character
    while(start<=end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
    return s;
}

string reverseString(string s){
    reverse(s.begin(),s.end());
    return s;
}

Reverses a string between [first,last)
reverse(s.begin(),s.begin()+2);

