https://leetcode.com/problems/find-median-from-data-stream/description/

.................................................................
Brute force ---> Insert - O(1) Find Median - O(nlogn)
https://drive.google.com/open?id=1TyEW_7rcaJ6yfrIKJM_osI1qWzlrq6hj
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> v;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        v.push_back(num);
        
    }
    
    double findMedian() {
        
    
        sort(v.begin(),v.end());
        
        int n=v.size();
        
        if(n==0){
            return NULL;
        }
        
        if(n%2!=0){
            return v[n/2];
        }
        else{
            return (v[(n/2)-1]+(double)v[n/2])/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
 
 
 ..........................................
 Using 2 heaps
 Time - Insert (logn) and find median (1)
 https://drive.google.com/open?id=1jjxkuG_15dTUbkOaZzw6vEdpkw3kEewE 

 class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lowers; // Max heap of lower elements or left side elements of median
    priority_queue<int,vector<int>,greater<int> > highers;  // Min heap of higher elements (Right side)
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // Add a number according to which side it belongs to
        
        // If num less than max element of lower elements then it should be on left side elements
        if(lowers.empty() || num<lowers.top()){
            lowers.push(num);
        }
        
        else{
            highers.push(num);
        }
        
        // Rebalance the 2 heaps
        // If size difference is 0(even elements) or 1(odd elements) then it's fine otherwise rebalance the heaps
        // Pop top element from bigger heap(size wise) to smaller heap(size wise) if size difference >=2 (Always =2 as can't be greater as we are balancing             everytime)
        
        int lowersSize=lowers.empty() ? 0:lowers.size();
        int highersSize=highers.empty() ? 0:highers.size();
    
        if(lowersSize-highersSize>=2){
            
            int element=lowers.top();
            lowers.pop();
            highers.push(element);
            
        }
        else if(highersSize-lowersSize>=2 ){
            
            int element=highers.top();
            highers.pop();
            lowers.push(element);
            
        }     
    }
    
    double findMedian() {
        
         // If size of both heaps equal then ans is average of top elements of both, otherwise top element of bigger heap(size wise)
        
        int lowersSize=lowers.empty() ? 0:lowers.size();
        int highersSize=highers.empty() ? 0:highers.size();
        
        // Both empty
        if(lowersSize==0 && highersSize==0){
            return NULL;
        }
        
        else if(lowersSize==highersSize){
            return (lowers.top()+(double)highers.top())/2;  // Imp double as 3/2 would result in 1 instead of 1.5
        }
        else if(lowersSize>highersSize){
            return lowers.top();
        }
        else{
            return highers.top();
        }
    }
    
};

