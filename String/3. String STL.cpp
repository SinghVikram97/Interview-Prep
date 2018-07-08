#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    cin>>s;

    /// Alphabetically sorted (Based on ascii values)
    sort(s.begin(),s.end());
    cout<<s<<endl;

    /// Length of string
    cout<<s.length()<<endl;

    /// Append to last and pop from last
    s.push_back('a');
    cout<<s<<endl;
    s.pop_back();
    cout<<s<<endl;

    /// Append a string at end
    s+="abc";
    cout<<s<<endl;

    /// Append another string
    string s2="bca";
    s.append(s2);
    cout<<s<<endl;

    /// Swap values with other string Time-O(1) just pointer redirected
    swap(s,s2);
    cout<<s<<endl;
    cout<<s2<<endl;

    /// Compare 2 strings
    /// <0 Either the value of the first character that does not match is lower in the compared string,
    /// or all compared characters match but the compared string is shorter.
    cout<<s.compare("cba")<<endl;  /// -1    'b'<'a' (ASCII)
    cout<<s.compare("aca")<<endl;  /// 1 as 'b'>'a'
    cout<<s.compare("bcaa")<<endl; /// -1 'bca' matches 'bca' but our string shorter

    if(s.compare("bca")==0){
        cout<<"Same strings"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }

    s+="bca";

    /// Find substring b/w i and j
    /// s is bcabca
    int i=1;
    int j=4;
    cout<<s.substr(i,j)<<endl;  /// cabc
    cout<<s.substr(i,s.length()-1)<<endl; /// from s[i] to end cabca

    /// Find position of substring (Return start position)
    cout<<s.find("cab")<<endl;

    /// Delete a subtring b/w i and j
    /// String is bcabca
    s.erase(i,j);
    cout<<s<<endl;

    /// Delete the whole string
    s.erase();
    cout<<s<<endl;
}
