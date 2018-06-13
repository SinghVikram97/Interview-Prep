https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0
https://www.geeksforgeeks.org/amazon-interview-set-89/

https://drive.google.com/open?id=1W2vc8A2c29C1CWM_nMlDBo4pwy0aQbWa
https://drive.google.com/open?id=1-tpTAe4pYCKJcerVY8ZKMM09dDjwPFW9


#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    
	    priority_queue<int,vector<int>,greater<int> > pq;  // Min_heap
	    
	    // Push all elements to the queue
	    for(int i=0;i<n;i++){
	        pq.push(v[i]);
	    }
	    
	    int cost=0;
	    
	    while(pq.size()!=1){
	        
	        // Take out 2 minimum length ropes
	        int first=pq.top();
	        pq.pop();
	        int second=pq.top();
	        pq.pop();
	        
	        // Add cost of merging them
	        cost+=first+second;
	        
	        // Push the resultant rope into queue
	        pq.push(first+second);
	        
	    }
	    
	    cout<<cost<<endl;
	    
	}
	return 0;
}
