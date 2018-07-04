https://www.geeksforgeeks.org/even-numbers-even-index-odd-numbers-odd-index/

https://drive.google.com/open?id=1k1DhpV13yuwh9aPchXB6SGTlkE3zKNb7

Doesn't maintain order
ex-> 1 2 3 1 6 4
Ouput-> 2 1 4 1 6 3 
If in order-> 2 1 6 3 4 1

Works only if equal no of odd and even nos then only possible to find odd and even no's at incorrect places or all at correct 
places

ex. 2 4 6,1 10
Won't work

void rearrange(vector<int> &v,int n){
    
    int evenIndex=0;
    int oddIndex=1;
    
    while(1){
        
        // Find 1st evenIndex that has odd no 
        while(evenIndex<n && v[evenIndex]%2==0){
            evenIndex+=2;
        }
        // Find 1st oddIndex that has even no
        while(oddIndex<n && v[oddIndex]%2==1){
            oddIndex+=2;
        }
        // Swap them
        if(evenIndex<n && oddIndex<n){
            swap(v[evenIndex],v[oddIndex]);
        }
        // Else it is end of array
        else{
            break;
        }
    }
}
