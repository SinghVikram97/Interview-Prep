#include<bits/stdc++.h>
using namespace std;
void printVector(vector<int> &v){

    if(!v.size()){
        cout<<"Empty"<<endl;
        return;
    }
    for(int i=0;i<v.size();i++){

        cout<<v[i]<<" ";

    }
    cout<<endl;

}
int main(){

    int n;
    cin>>n;
    vector<int> v(n);  /// Allocates a vector of size n with elements as 0
    v.push_back(1);  /// Gets inserted after n elements
    printVector(v);
    sort(v.begin(),v.end(),greater<int>());  /// Sorting in decreasing order
    /// By default is increasing order
    printVector(v);
    v.pop_back();
    printVector(v);
    v.clear();          /// Time--> O(n)
    printVector(v);



}
