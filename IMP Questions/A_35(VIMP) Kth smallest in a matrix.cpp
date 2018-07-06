https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
.................................
1. SORT

ADD ALL ELEMENTS TO THE LIST
SORT THE LIST
AND RETURN THE KTH ELEMENT
....................................
    
2. BRUTE FORCE->
SIMILAR APPROACH TO THIS
KTH LARGEST IN AN ARRAY
https://github.com/SinghVikram97/Interview-Prep/blob/master/Heaps/2.%20(VIMP)%20Kth%20Largest%20Element%20in%20Array.cpp

https://drive.google.com/open?id=1CkMy04j8saesCydZVaACRBlDv0Zq3wng

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {


        int n=mat.size();
        priority_queue<int> pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // Push 1st k elements to the max heap
                if(pq.size()<k){
                    pq.push(mat[i][j]);
                }
                // After that if a smaller no appears than priority queue's top remove from pq and add it
                else{
                    if(mat[i][j]<pq.top()){
                        pq.pop();
                        pq.push(mat[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};
..................................................
 3. Using min heap O(klogk)
    
    https://drive.google.com/open?id=10yUy4ACwMf3M8Tf5uSjySNRQpnWtZv6m

    As the row and column are both sorted we can deduce that the element at [i,j] < [i+1,j] and [i,j] < [i,j+1].

    Algo:
    -Add the first element to the tree set
    -Till the kth smallest element is found remove the first element (i,j) from set and add next 2 elements (i+1,j) and (i,j+1) if they have not visited before

    Time Complexity : O(KlogK) 
    Space complexity : O(K)
        
     The key observation is that: after we fetch the top element (the minimum) from the min-heap, 
     the next minimum of the matrix can only be found among the remaining elements of the heap + 
     the two neighbors of the fetched top element (rightward and downward). 


    
    struct matElement{

    int value;
    int row;
    int col;

    matElement(int v,int r,int c){

        value=v;
        row=r;
        col=c;
    }

    bool operator < (const matElement &m) const{
            /// Min heap
            if(value>m.value){
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
        
            // 3. Now for k-1 pop from min heap the smallest element. At kth step we will have the kth minimum element as we
            // we have removed k-1 smaller elements
            
            for(int i=0;i<k-1;i++){
                
                matElement mini=pq.top();
                pq.pop();
                
                // Add downward element
                if(mini.row+1<m){
                    pq.push(matElement(v[mini.row+1][mini.col],mini.row+1,mini.col));
                }
                // Add rightward element only for elements of 1st row
                // If we add rightward element for all then duplicates will be added
                if(mini.row==0 && mini.col+1<n){
                    pq.push(matElement(v[mini.row][mini.col+1],mini.row,mini.col+1));
                }               
            }
           return pq.top().value;
    }
};
