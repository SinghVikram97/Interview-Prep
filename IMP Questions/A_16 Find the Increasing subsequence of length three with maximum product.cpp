 Given an array of size n consisting of positive integers,
 choose three integers(not necessarily contiguous) such that they are in ascending order and their product is maximum.
 
 https://www.geeksforgeeks.org/increasing-subsequence-of-length-three-with-maximum-product/
 
 https://drive.google.com/open?id=1WBVL1rUylH_HqIlE8IK_Qw2JvHIh-R82 
 https://drive.google.com/open?id=15fdHNWen8YgMZemYrjmjAvQ8wJq3ywup (USING BST)
 
 void sequence(vector<int> &v,int n){

    if(n<3){
        cout<<-1<<endl;
        return;
    }

    // Largest smallest element on left
    vector<int> lsl(n);
    // Largest greater element on right
    vector<int> lgr(n);

    // Fill the lsl and lgr
    for(int i=1;i<=n-2;i++){

        lgr[i]=-1;
        for(int j=i+1;j<n;j++){
            lgr[i]=max(lgr[i],v[j]);
        }
        // If not element greater on right
        // ex. 1 5 10 8 9   If we don't include this for 10 lgr would come out to be 9 and seqence 5 10 9 would be produced as ans
        if(lgr[i]<v[i]){
            lgr[i]=-1;
        }

        lsl[i]=-1;
        for(int j=i-1;j>=0;j--){
            if(v[j]<=v[i] && v[j]>lsl[i]){
                lsl[i]=v[j];
            }
        }
    }

    // Print element with larget lsl[i]*v[i]*lgr[i]
    int maxIndex;
    int maxProduct=-1;
    int product;
    for(int i=1;i<=n-2;i++){

        product=lsl[i]*v[i]*lgr[i];

        if(product>maxProduct){
            maxProduct=product;
            maxIndex=i;
        }
    }

    // Print the tuple
    cout<<lsl[maxIndex]<<" "<<v[maxIndex]<<" "<<lgr[maxIndex]<<endl;
}
