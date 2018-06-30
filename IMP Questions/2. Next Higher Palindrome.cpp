https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits/0

https://drive.google.com/open?id=1-MbMxmaE7Ct-VdGl3lUwlnRrOrraZD_C (IMP)
https://drive.google.com/open?id=14wFvYy4f8NxJqQ8A6P0O3_0i8rE28h96

EXACTLY LIKE NEXT HIGHER PERMUTATION PROBLEM JUST START FROM MID TO 0 AND FIND NEXT HIGHER PERMUTATION
AFTER THAT JUST COPY NUMBERS TO SECOND HALF

string nextPalindrome(string v){
    
    int n=v.length();
    int mid=(n/2)-1; // IMP
    int pos=-1;
    
    // Find a no that is less than it's next starting from mid
    for(int i=mid;i>=1;i--){
        
        if(v[i-1]<v[i]){
            pos=i-1;
            break;
        }
        
    }
    if(pos==-1){
        return "-1";
    }
    
    // Find a least no from pos+1 to mid that is greater than no at the pos
    int numPos=-1;
    for(int i=pos+1;i<=mid;i++){
        if(v[i]>v[pos]){
           
           if(numPos==-1){
               numPos=i;
           }
           else{
               if(v[i]<v[numPos]){
                   numPos=i;
               }
           }
           
        }
    }
    // Swap the numbers at pos and numPos
    swap(v[pos],v[numPos]);
    
    // Now sort the numbers from pos+1 to mid or reverse
    // Also we have used v.begin()+mid+1 as for last argument sort excludes last index
    sort(v.begin()+pos+1,v.begin()+mid+1);
    
    // Now mirror the same no from 0 to mid ---> to depends on length odd or even
    int i=0;
    int j=n-1;
    while(i<=mid){
        v[j]=v[i];
        i++;
        j--;
    }
    return v;
}
