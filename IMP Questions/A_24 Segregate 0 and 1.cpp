https://practice.geeksforgeeks.org/problems/binary-array-sorting/0

Like Quicksort

void rearrange(vector<int> &v,int n){
    
    // Bring all zero elements to front
    int zeroElements=-1;  (WALL)
    for(int i=0;i<n;i++){
        if(v[i]==0){
            zeroElements++;
            swap(v[i],v[zeroElements]);
        }
    }
    
}
