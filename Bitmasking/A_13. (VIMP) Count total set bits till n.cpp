https://practice.geeksforgeeks.org/problems/count-total-set-bits/0

https://drive.google.com/open?id=1dHBK3lAW2vaGieGd6o360ByKBSj_RNiT

int count(int n)
{
    // Iterate for every bit
    int sum=0;
    
    for(int i=0;i<32;i++){
        
        int blockSize=pow(2,i+1);
    
        int completeBlocks=(n+1)/(blockSize);
        
        int number_of_ones=pow(2,i)*(completeBlocks);
        
        int incompleteBlock=(n+1)%(blockSize);
        
        int remainder_ones=incompleteBlock-(pow(2,i));
        
        if(remainder_ones>0){
            number_of_ones+=remainder_ones;
        }
        
        sum=sum+number_of_ones;
        
    }
    return sum;
}
