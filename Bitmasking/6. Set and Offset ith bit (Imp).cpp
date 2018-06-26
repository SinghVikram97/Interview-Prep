https://practice.geeksforgeeks.org/problems/set-kth-bit/0

https://drive.google.com/open?id=1HkIb9kyDShNupbV6cQsJf1ed_XVEZUm3

int afterSettingKthBit(int n,int i){
    
    int temp=1<<i;
    
    int ans=temp|n;
    
    return ans;
    
} 

https://drive.google.com/open?id=1BKJ53n7zfb2QFUCzVJIYVFVSKWDXVxyd

int afterOffsettingKthBit(int n,int i)
{
   
    int temp=1<<i;
 
    temp=~temp;
 
    n=n&temp;
    
    return ans;
    
}
