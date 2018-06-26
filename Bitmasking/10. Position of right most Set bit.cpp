https://practice.geeksforgeeks.org/problems/find-first-set-bit/0

int pos(int n){
    
    int temp=n&(~(n-1));
    
    int count=0;
    
    while(temp!=0){
        count++;
        temp=temp>>1;
    }
    return count;
}
