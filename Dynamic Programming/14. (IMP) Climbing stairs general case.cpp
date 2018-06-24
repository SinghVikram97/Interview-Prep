https://drive.google.com/open?id=1rID7MdAu1kiT9QBM6VJSgWAlHA2B4ABG
https://drive.google.com/open?id=1p-XcAenN0ANFCwejEygemvFfcgYcjBu0

Time Complexity= O(n*k)
#include<bits/stdc++.h>
using namespace std;
/// f(n)=f(n-1)+f(n-2)+f(n-3)+f(n-4)............f(n-k)
int count_ways(int n,int k)
{
   int dp[n+1]; /// dp[i] denotes ways to reach ith step
   /// Calculate for 1st k steps
   dp[0]=1; /// Floor
   dp[1]=1;
   for(int i=2;i<=k;i++)
   {
     dp[i]=2*dp[i-1];
   }
   /// Calculate for steps after k
   for(int i=k+1;i<=n;i++)
   {
        dp[i]=0;
        /// dp[i] is sum of dp[i-1]+dp[i-2].....dp[i-k]
        for(int j=1;j<=k;j++)
        {
          dp[i]=dp[i]+dp[i-j];
        }
   }
   return dp[n];
}
int main()
{
   int n;  /// nth step
   cin>>n;
   int k;
   cin>>k; /// maximum jump
   cout<<count_ways(n,k);
}


.................................................
Time Complexity=O(n+k)
#include<bits/stdc++.h>
using namespace std;
/// f(n)=f(n-1)+f(n-2)+f(n-3)+f(n-4)............f(n-k)
/// f(n)=2*f(n-1)-f(n-(k+1))
int count_ways(int n,int k)
{
   int dp[n+1]; /// dp[i] denotes ways to reach ith step
   /// Calculate for 1st k steps
   dp[0]=1; /// Floor
   dp[1]=1;
   for(int i=2;i<=k;i++)
   {
     dp[i]=2*dp[i-1];
   }
   /// Calculate for steps after k
   for(int i=k+1;i<=n;i++)
   {
        dp[i]=2*dp[i-1]-dp[i-(k+1)];
   }
   return dp[n];
}
int main()
{
   int n;  /// nth step
   cin>>n;
   int k;
   cin>>k; /// maximum jump
   cout<<count_ways(n,k);
}
