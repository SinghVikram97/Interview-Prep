https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

Also called sliding window of size =k

https://drive.google.com/open?id=14tXs4lt_DEE9zeLmPyqVmBo3W30mwQu3

1. We scan the array from 0 to n-1, keep "promising" elements in the deque. The algorithm is amortized O(n) as each element is pushed and popped once

2. At each i, we keep "promising" elements, which are potentially max number in window [i-(k-1),i] or any subsequent window. This means

3. If an element in the deque and it is out of i-(k-1), we discard them. We just need to pop from the head, as we are using a deque and elements are ordered as the sequence in the array

4. Now only those elements within [i-(k-1),i] are in the deque. We then discard elements smaller than a[i] from the tail. This is because if a[x] <a[i] and x<i, then a[x] has no chance to be the "max" in [i-(k-1),i], or any other subsequent window: a[i] would always be a better candidate.

5 .As a result elements in the deque are ordered in both sequence in array and their value. At each step the head of the deque is the max element in [i-(k-1),i]


void solve(vector<int> &v,int n,int k){
  
  // Storing the indices
  deque<int> dq;
  
  // For 1st k elements push into deque
  for(int i=0;i<k;i++){
      
      // Remove elements smaller than current element (As deque always sorted in decreasing order)
      while(!dq.empty() && v[i]>v[dq.back()]){
          dq.pop_back();
      }
      
      // Now push the current element
      dq.push_back(i);
  }
  
  // Output the answer for 1st subarray from 0 to k-1
  // As it is sorted in decreasing order maximum always at the front
  cout<<v[dq.front()]<<" ";
  
  
  // Subarray from i-k+1 to i
  for(int i=k;i<n;i++){
      
      // Discard all elements from deque which are not part of current subarray
      while(!dq.empty() && dq.front()<=(i-k)){
          dq.pop_front();
      }
      
      // Remove elements smaller than current element (As deque always sorted in decreasing order)
      while(!dq.empty() && v[i]>v[dq.back()]){
          dq.pop_back();
      }
      
       // Now push the current element
       dq.push_back(i);
      
      // Output the answer for this subarray
      cout<<v[dq.front()]<<" ";
      
  }
 cout<<endl;
}

Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that 
every element of array is added and removed at most once. So there are total 2n operations.
Auxiliary Space: O(k)
