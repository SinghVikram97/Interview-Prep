
Brute Force- O(nlogn)
    
SORT THE ARRAY AND RETURN THE KTH ELEMENT

https://drive.google.com/open?id=1WC2KnvqTyH3ZM1IbLy3pZmd5rtTUpr2l

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k!=1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};

.................................................
Using min_heap  Time-O(k+ (n-k)logk)  log k for popping and n-k for loop

SIMILARLY FOR KTH SMALLEST ELEMENT TOP OF MAX HEAP OF K SMALLEST ELEMENTS OF ARRAY

https://drive.google.com/open?id=1wXWsT_R9RI4EC5z31zZjDfk6ldAcnDbR

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        priority_queue<int,vector<int>,greater<int> > pq;  // Build a min_heap of k largest elements of the list
        
        for(int i=0;i<k;i++){
            pq.push(nums[i]);   // Push 1st k elements to the list we assume this is our final list of k largest elements
        }
        
        for(int i=k;i<n;i++){
            
            
            if(nums[i]>pq.top()){
                
                pq.pop();
                
                pq.push(nums[i]);
                
            }
        }
        return pq.top();
    }
};
