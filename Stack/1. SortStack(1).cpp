https://practice.geeksforgeeks.org/problems/sort-a-stack/1

https://drive.google.com/open?id=16UUE45V6ISEWByqfhyII46Z8H9g8VgkK  (Not O(n) it's O(nlogn))

   void SortedStack :: sort()
{
   //Your code here
   
   // 1. Store in a vector
   vector<int> v;
   while(!s.empty()){
       
       int element=s.top();
       v.push_back(element);
       s.pop();
       
   }
   
   // 2. Sort the vector
   std::sort(v.begin(), v.end());          // If we don't use std::sort it goes into SortedStack::sort and error
   
   // 3. Push back into stack
   for(int i=0;i<v.size();i++){
        
        s.push(v[i]);
       
    }
}
