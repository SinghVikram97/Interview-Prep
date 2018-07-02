https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad/0

https://drive.google.com/open?id=14gekB6MMm8eHYQybHiV9AaLi9qRF65sZ

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<char> > keypad={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};
vector<int> row={0,-1,0,1,0};
vector<int> col={0,0,1,0,-1};
ll dfs(int i,int j,int length,int n,ll dp[][5][4]){
    
    if(length==n){
        return 1;
    }
    
    if(dp[length][i][j]==-1){
         // Can move 5 positions
        int r,c;
        ll count=0;
        for(int move=0;move<5;move++){
            r=i+row[move];
            c=j+col[move];
            // New position is [r,c]
        
            // Check if valid position
            if(r>=0 && r<=3 && c>=0 && c<=2 && keypad[r][c]!='*' && keypad[r][c]!='#'){
                count+=dfs(r,c,length+1,n,dp);
            }
        }
      dp[length][i][j]=count;
    }
    return dp[length][i][j];
}
ll possibleCombinations(int n,ll dp[][5][4]){
    
    ll totalCount=0;
    // Start from a given no in the keypad and do dfs till length!=n
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(keypad[i][j]!='*' && keypad[i][j]!='#'){
                totalCount+=dfs(i,j,1,n,dp);  // Length passed is 1 (NOT 0) as we have pressed this button intially 
            }
        }
    }
    return totalCount;
}
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        ll dp[n+1][5][4];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=4;j++){
                for(int k=0;k<=3;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        cout<<possibleCombinations(n,dp)<<endl;
        
    }
}
