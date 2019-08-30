https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

struct matElement{
    
    int val;
    int r;
    int c;
    
    matElement(int v,int i,int j){
        val=v;
        r=i;
        c=j;
    }
    
    
    // Custom comparator for min heap
    bool operator < (const matElement &m) const{
            /// Min heap
            if(val>m.val){
                return true;
            }
            else{
                return false;
            }
    }
    
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
        
        int m=v.size();  // Rows 
        int n=v[0].size(); // Columns
        
        
        // 1. Create a min heap
        priority_queue<matElement> pq;
        
        // 2. Insert first element into min heap
        pq.push(matElement(v[0][0],0,0));
        
        
         // 3. Now for k-1 pop from min heap the smallest element. At kth step we will have the kth             minimum element as we
        // we have remove k-1 smaller elements
        
         for(int i=0;i<k-1;i++){
            
            matElement mini=pq.top();
            pq.pop();
            
            if(mini.r+1<m){
                    pq.push(matElement(v[mini.r+1][mini.c],mini.r+1,mini.c));
            }
            
            if(mini.r==0 && mini.c+1<n){
                    pq.push(matElement(v[mini.r][mini.c+1],mini.r,mini.c+1));
            }   
            
        }
        return pq.top().val;
    }
};
