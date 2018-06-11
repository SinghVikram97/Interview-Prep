https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

https://drive.google.com/open?id=1pZfhEdzTo26N4gAKYp6WG-sga9Hrx6Ty

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	
	int t;
	cin>>t;
	while(t--){
	    
	    string text;
	    cin>>text;
	    stack<char> s;
	    bool balanced=true;
	    
	    for (int i=0;i<text.length();i++){
	        
	        if(text[i]=='[' || text[i]=='{' || text[i]=='('){
	            s.push(text[i]);
	        }
	        else{
	            
	            if(s.empty()){
	                balanced=false;
	                break;
	            }
	            char ele=s.top();
	            s.pop();
	            
	            if(text[i]==']' && ele!='['){
	                balanced=false;
	                break;
	            }
	            else if(text[i]==')' && ele!='('){
	                balanced=false;
	                break;
	            }
	            if(text[i]=='}' && ele!='{'){
	                balanced=false;
	                break;
	            }
	        }
	        
	    }
	    if(balanced && s.empty()){
	        cout<<"balanced"<<endl;
	    }
	    else{
	        cout<<"not balanced"<<endl;
	    }
	  }
	
	return 0;
}
