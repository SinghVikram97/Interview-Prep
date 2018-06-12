https://practice.geeksforgeeks.org/problems/generate-binary-numbers/0

https://drive.google.com/open?id=13gffHXYTlh4YYfwA2IR-Wk-uhGaUGX08
https://drive.google.com/open?id=1kCJ7CfQks8HhFdxtH_Jv71RtBCTNLdYG

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    
	    int n;
	    cin>>n;
	    queue<string>  q;
	    q.push("1");
	    
	    for(int i=1;i<=n;i++){
	        
	        string s=q.front();
	        q.pop();
	        cout<<s<<" ";
	        
	        string s1=s;
	        
	        q.push(s.append("0"));
	        q.push(s1.append("1"));
	        
	    }
	    
	    cout<<endl;
	    
	}
	
	return 0;
	
}
