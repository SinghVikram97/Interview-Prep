https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos/0

BruteForce- Time O(N) Space O(N)

void alternate(vector<int> &v,int n){
    
    vector<int> positive;
    vector<int> negative;
    
    for(int i=0;i<n;i++){
        
        if(v[i]>=0){
            positive.push_back(v[i]);
        }
        else{
            negative.push_back(v[i]);
        }
    }
    
    int positiveIndex=0;
    int negativeIndex=0;
    int i=0;
    int positiveSize=positive.size();
    int negativeSize=negative.size();
    
    while(positiveIndex<positiveSize && negativeIndex<negativeSize){
        
        if(i%2==0){
            
            v[i]=positive[positiveIndex];
            i++;
            positiveIndex++;
        }
        else{
            v[i]=negative[negativeIndex];
            i++;
            negativeIndex++;
        }
    }
    while(positiveIndex<positiveSize){
        
            v[i]=positive[positiveIndex];
            i++;
            positiveIndex++;
    }
    while(negativeIndex<negativeSize){
            v[i]=negative[negativeIndex];
            i++;
            negativeIndex++;
    }
}
