https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos/0

// IF ORDER DOESN'T MATTER
---------------------------------------------------------------------------------------------

https://drive.google.com/open?id=1CM4b3Y2YSpk2VfYgnpw0ALQEYXR2q3hB (Rearrange odd even is diff)
HERE NOT EQUAL NUMBER OF +VE AND -VE NUMBERS AND IF NOT EQUAL WE WANT THEM AT THE END
WE CAN USE THE SAME TECHNIQUE IN ODD EVEN QUESTION IF NOT EQUAL

----------------------------------------------------------------------------------------------
ALGO-https://drive.google.com/open?id=1XH6RrhjppQtETG3C3DTiFyiHqoZjMFE7
----------------------------------------------------------------------------------------------

void rearrange(vector<int> &v,int n){
    
    // Move all positive numbers to the end(negative numbers to front)
    int wall=-1;
    for(int i=0;i<n;i++){
        if(v[i]<0){
            wall++;
            swap(v[wall],v[i]);
        }
    }
    
    // Now wall is at position of last -ve number
    
    // If no negative number or all -ve numbers
    if(wall==-1 || wall==n-1){
        return;
    }
    
    // Else start from begining of array and position of 1st +ve num
    int i=0,positiveStart=wall+1;
    while(i<n && positiveStart<n){
        swap(v[i],v[positiveStart]); 
        i=i+2;  // Next even position
        positiveStart=positiveStart+1; // Next positive no
    }
}
