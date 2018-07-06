https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
....................................
BRUTE FORCE->
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
