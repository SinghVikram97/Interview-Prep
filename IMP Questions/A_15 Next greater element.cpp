https://practice.geeksforgeeks.org/problems/greater-on-right-side/0

int replace(vector<int> &v,int n){
    
    // Start from right and keep track of max til now
    int maxi=-1;
    int temp;
    for(int i=n-1;i>=0;i--){
        
        temp=v[i];
        v[i]=maxi;
        maxi=max(temp,maxi);
    }
}

For largest greater element to the right
if(maxi>v[i])
{
    lgr[i]=maxi;
}
else{
    lgr[i]=-1;
    maxi=v[i];
}
