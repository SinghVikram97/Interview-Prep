https://practice.geeksforgeeks.org/problems/bit-difference/0

int countFlipBits(int a,int b){
    
    // No of bits to flip is equal to number of set bits in xor of a and b
    // Because xor is 1 if both bits are different and 0 if both bits same
    int xorAB=a^b;
    
    // Now count set bits
    int count=0;
    
    while(xorAB){
        
        count++;
        xorAB=(xorAB&(xorAB-1));
        
    }
    return count;
}
