https://practice.geeksforgeeks.org/problems/implement-atoi/1/

int atoi(string s)
{
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            ans=(ans*10)+(s[i]-'0');
        }
        else if(s[i]=='-'){
            continue;
        }
        // If any other character than a number
        else{
            return -1;
        }
    }
    if(s[0]=='-'){
        return -1*ans;
    }
    else{
        return ans;
    }
}

// Library function for conversion of '123' to 123
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=stoi(s);  /// -123--> -123  but if --123 or a123 throws a error
    cout<<n;
}
