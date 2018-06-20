https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

https://drive.google.com/open?id=1eiAqFc8AoEUE8E5vZT7qijppzNnpLwXN
https://drive.google.com/open?id=1y8G_44VaxQot3_aCpA0X0UVfXo5ougsC
https://drive.google.com/open?id=1dMC0kd4hyChXHLobvzyEFMXGgO1a1tDp

void solve(vector<int> &v,int n,int k){
  
  priority_queue<pair<int,int> > pq;
  
  // Insert 1st k elements
  for(int i=0;i<k;i++){
      pq.push(make_pair(v[i],i));
  }
  
  // Output the ans for 1st k elements
  cout<<pq.top().first<<" ";
  
  // For subarrays from [i-k+1,i] 
  for(int i=k;i<n;i++){
      
      // Remove elements from top which are not a part of current subarray from [i-k+1,i]
      // <=(i-k) as current subarray from i-k+1
      
      while(!pq.empty() && pq.top().second<=(i-k)){
          pq.pop();
      }
      
      // Push current element
      
      pq.push(make_pair(v[i],i));
      
      // Output the answer for current element
      
      cout<<pq.top().first<<" ";
  }
  
  cout<<endl;
}
