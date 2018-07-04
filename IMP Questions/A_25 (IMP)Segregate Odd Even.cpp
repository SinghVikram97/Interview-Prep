https://www.geeksforgeeks.org/segregate-even-and-odd-numbers/

https://drive.google.com/open?id=1F6O9DeDAATdzm4RgEFkEI6iXAClFsKeP

MAINTAINS ORDER FOR ELEMENTS WE ARE MOVING TO FRONT IE. EVEN ELEMENTS
BUT NOT FOR ODD ELEMENTS

void rearrange(vector<int> &v,int n){
    
    int lastEven=-1;
    for(int i=0;i<n;i++){
        if(v[i]%2==0){
            lastEven++;
            swap(v[i],v[lastEven]);
        }
    }
    
}
