https://practice.geeksforgeeks.org/problems/key-pair/0

https://drive.google.com/open?id=16UEHSdGyJZ8vNStc8uprql1J5eunevxi

If you need without extra space sort the array and find pair whose sum is k (See next program)

bool findPair(vector<int> &v,int n,int k){
    
    unordered_set<int> s;
    
    for(int i=0;i<n;i++){
        
        // Search for k-v[i] in set
        if(s.find(k-v[i])!=s.end()){
            return true;
        }
        // If not found insert v[i] in set
        s.insert(v[i]);
        
    }
    return false;
}

