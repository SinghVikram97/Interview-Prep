https://drive.google.com/open?id=1oX3j5KmftmR511dh3HxJzJk2v45eb_qh
https://drive.google.com/open?id=1jIkLZOsQ8D_lfoyeetgIPI0xOIdYkgKd

int lcs(string &s1,string &s2,int m,int n){
    
    // Base cases
    // dp[i][0]=0 and dp[0][j]=0
    // dp[i][j] denotes lcs upto i and j  (1 based indexing)
    // So dp[m][n] is our final ans
    
    int dp[m+1][n+1];  // matric from [0...m][0...n]
    
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            
            // As string is 0 based indexing so we substract 1
            if(s1[i-1]==s2[j-1]){
                
                dp[i][j]=1+dp[i-1][j-1];
                
            }
            else{
                
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
            
        }
    }
    
    int i=m,j=n;
    string ans="";
    while(i>=1 && j>=1){
        
        /// Move diagonally upward and include current character in final ans
        // Imp i-1 and j-1 as given string 0 based
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }
        
        else{
            
            if(dp[i-1][j]>=dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
            
        }
        
    }
    
    // Reverse it if you want actual ordering
    reverse(ans.begin(),ans.end());
    cout<<ans<<" ";
    return dp[m][n];
    
}
