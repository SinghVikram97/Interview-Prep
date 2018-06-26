https://practice.geeksforgeeks.org/problems/set-bits/0

https://drive.google.com/open?id=1TMYKzlAIjCtyuwhi9jnjEyFNOSBfiotV

https://drive.google.com/open?id=1xWq1ru4hmBgeIFHm50qcosRYhvOnnUXL (IMP) 

// O(no of bits) ie sizeof(int)
int setBitsCount1(int n){
    
    int count=0;
    
    while(n!=0){
        
        if(n&1){
            count++;
        }
        
        n=n>>1;
        
    }

    return count;
    
}
// O(no of set bits)
int setBitsCount2(int n){
    
    int count=0;
    
    /// Removes last set bit in each iteration
    while(n){
        count++;
        n=n&(n-1);
    }
    return count;
}
