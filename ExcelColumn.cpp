https://careercup.com/question?id=64115

0-A 1-B..............25-Z
26-AA 27-AB

#include<bits/stdc++.h>
using namespace std;
int main(){

    int num;
    cin>>num;
    string s="";
    while(num>=0){
        int rem=num%26;
        char temp='A'+rem;
        s=temp+s;
        num=(num/26)-1;
    }
    cout<<s<<endl;
}

1-A 2-B...........26-Z , 27-AA 28-AB
#include<bits/stdc++.h>
using namespace std;
int main(){

    int num;
    cin>>num;
    num=num-1; ----> Only change this
    string s="";
    while(num>=0){
        int rem=num%26;
        char temp='A'+rem;
        s=temp+s;
        num=(num/26)-1;
    }
    cout<<s<<endl;
}

