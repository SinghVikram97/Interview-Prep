MAINTAINS ORDER

ALGO---> IF ANY ELEMENT OUT OF PLACE FIND JUST NEXT CORRECT ELEMENT THAT SHOULD HAVE BEEN THERE AND RIGHT ROTATE THE 
ARRAY BY ONE B/W THESE 2 NUMBERS

https://drive.google.com/open?id=1aX7HmjLuTYIn5K9n05PcE9nWOKrBx5T6


void rotate(vector<int> &v,int start,int end){
    
    // Store last element
    int last=v[end];
    // Shift other elements by one
    for(int i=end-1;i>=start;i--){
        v[i+1]=v[i];
    }
    // Insert last element at start
    v[start]=last;
    
}
void rearrange(vector<int> &v,int n){
    
   for(int i=0;i<n;i++){
       
       // If index even and number -ve we need to fix
       if(i%2==0 && v[i]<0){
           
           // Find next positive number
           int nextPIndex=-1;
           for(int j=i+1;j<n;j++){
               if(v[j]>=0){
                   nextPIndex=j;
                   break;
               }
           }
           // If no next positive number it means all -ve numbers left now
           if(nextPIndex==-1){
               break;
           }
           // Rotate the array right by one
           else{
               rotate(v,i,nextPIndex);
           }
       }
       // If index odd and number +ve
       else if(i%2==1 && v[i]>=0){
          
           // Find next negative number
           int nextNIndex=-1;
           for(int j=i+1;j<n;j++){
               if(v[j]<0){
                   nextNIndex=j;
                   break;
               }
           }
           // All +ve numbers left
           if(nextNIndex==-1){
               break;
           }
           // Rotate by one
           else{
               rotate(v,i,nextNIndex);
           }
       }
   }
}
