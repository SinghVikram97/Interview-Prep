*****************************************************************************
                          bool operator(T a, T b); 
If it returns true, it means that a is placed before b in the sorted ordering.
*****************************************************************************


#include<bits/stdc++.h>
using namespace std;
void printVector(vector<pair<int,int> > v){

    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
}
/// Comparator which sorts in increasing order according to 1st element
/// But if 1st element same then picks element with larger 2nd value
bool myComp(pair<int,int> &v1,pair<int,int> &v2){

    if(v1.first<v2.first){
        return true;
    }
    else if(v1.first==v2.first){

        if(v1.second>v2.second){
            return true;
        }
        else{
            return false;
        }

    }
    else{
        return false;
    }
}
int main(){

  int n;
  cin>>n;
  vector<pair<int,int> > v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
  }
  cout<<endl;
  printVector(v);

  /// Sorting
  /// **Note not greater<int>
  //  sort(v.begin(),v.end(),greater<pair<int,int> >()); /// By default sorts by 1st element and if 1st element same then looks at second to decide
  //  printVector(v);

  /// Custom comparator
  sort(v.begin(),v.end(),myComp);
  printVector(v);

}
