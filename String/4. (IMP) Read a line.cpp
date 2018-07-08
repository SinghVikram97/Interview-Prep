#include<bits/stdc++.h>
using namespace std;
int main(){

    /// Read a string with spaces
    string s;
    getline(cin,s);  /// Stops reading when it encounters a /n
    cout<<s<<endl;

    /// We can change the delimiter
    string s1;
    getline(cin,s1,'$');  /// abc abc d$abc --> Only reads abc abc d
    cout<<s1<<endl;

    /// Combining cin and getline
    /// cin ignores any newline character '/n' so this works fine
    /// So after we use cin and press enter there is '/n' in buffer
    /// And if we use getline after that it encounters that '/n' and stops reading immediately
    int n;
    cin>>n;
    string s2;
    getline(cin,s2);
    cout<<n<<" "<<s2<<endl; /// Prints n and empty string

    int t;
    cin>>t;
    cin.ignore(); /// Reads a char and throws it away
    string s3;
    getline(cin,s3);
    cout<<t<<" "<<s3<<endl;  /// Now works fine
}
