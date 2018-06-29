#include<bits/stdc++.h>
using namespace std;
void printVector(vector<vector<int> > &v){

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){

   int row,col;
   cin>>row>>col;

   vector<vector<int> > v(row,vector<int>(col));

   for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
            cin>>v[i][j];
       }
   }
    printVector(v);

}
