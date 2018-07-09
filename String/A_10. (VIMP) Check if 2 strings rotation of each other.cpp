https://leetcode.com/problems/rotate-string/description/

BRUTE FORCE-O(N2) TIME O(1) SPACE
....................................................................
https://drive.google.com/open?id=1FRcjp7r7sxLCw1mPKlOwE_ycDxcTy6oA

bool rotateString(string A, string B) {
        
        if(A.length()!=B.length()){
            return false;
        }
        int k=1;  // Rotate by 1 to length positions
        int n=A.length();
        if(n==0){
            return true;
        }
        bool rotations;
        for(int k=1;k<=n;k++){
            rotations=true; // Assume to be true
            for(int i=0;i<n;i++){
                if(A[i]!=B[(i+k)%n]){
                   // Reject this k
                    rotations=false;
                    break;
                }
            }
            if(rotations){
                return true;
            }
        }
        return false;
    }

USING SUBSTRING APPROACH
.................................................................................
TIME-O(N^2) OR O(N) DEPENDING UPON THE IMPLEMENTATION OF FIND FUNCTION IN C++ STL
SPACE- O(N) FOR STORING A+A

https://drive.google.com/open?id=12i75YeJbtZ4l4F1PA70ImnCqBHqIhCFv

bool rotateString(string A, string B) {
        
        if(A.length()!=B.length()){
            return false;
        }
        if(A.length()==0){
            return true;
        }
        // string::npos means starting position of string B in string (A+A) is end of string
        if((A+A).find(B)!=string::npos){
            return true;
        }
        else{
            return false;
        }
}

