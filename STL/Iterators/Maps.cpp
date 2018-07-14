#include<bits/stdc++.h>
using namespace std;
int main(){

    map<int,int> myMap;
    myMap.insert(make_pair(0,1));
    myMap.insert(make_pair(1,2));
    myMap.insert(make_pair(2,3));

    /// 3 ways to traverse the map
    /// Iterator which is a pointer to container element
    for(auto it=myMap.begin();it!=myMap.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<endl;

    /// here "it" is a pointer it means it->first==(*it).first
    for(auto it=myMap.begin();it!=myMap.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    cout<<endl;

    /// Shorthand if don't want a pointer and just want direct acess
    /// Map is pair so .first and .second
    for(auto member:myMap){
        cout<<member.first<<" "<<member.second<<endl;
    }

    cout<<endl;

    /// But c++ functions always return an iterator
    /// ex. myMap.begin() returns an iterator which is a pointer
    auto it=myMap.find(0);

    /// Can't directly do
    /// cout<<it.first<<endl;

    /// Instead
    cout<<(*it).first<<endl;

    /// Or
    cout<<(it)->first<<endl;

}
