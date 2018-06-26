https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

int missingNumber(vector<int> v){
    
    int n=v.size()+1;
    
    int xorAll=0;
    
    // Take xor of all numbers of v
    for(int i=0;i<v.size();i++){
        xorAll=xorAll^v[i];
    }
    
    // Take xor of all numbers from 1 to n (Duplicate numbers will get cancelled)
    for(int i=1;i<=n;i++){
        xorAll=xorAll^i;
    }
    
    // Return the unique no
    return xorAll;
}
