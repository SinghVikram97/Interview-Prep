#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
    int start=0;
    int end=s.length()-1;
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int addChar(string s){

    int i=0;
    while(s.length()>0){

        if(isPalindrome(s)){
            return i;
        }
        else{
            i++;
            // Erase the last character of string
            s=s.substr(0,s.length()-1);
        }
    }
    return i;
}
int main(){

    string s;
    cin>>s;
    cout<<addChar(s)<<endl;

}
