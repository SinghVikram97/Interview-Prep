https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos/0

O(N) TIME O(N) SPACE

https://drive.google.com/open?id=1uzhiJ8hHnmy1TvwxB6qYqcJ5FBmZfK_V

void rearrange(vector<int> &v,int n){
    
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
    
    // Find whether positive numbers are less or negative numbers
    // For 2*size index can be filled by alternating
    int size=positive.size()<=negative.size()?positive.size():negative.size();
    int index=0;
    int i;
    for(i=0;i<size;i++){
        v[index]=positive[i];
        v[index+1]=negative[i];
        index=index+2;
    }
    
    // After that fill the remaining array with numbers that were in majority
    if(positive.size()>negative.size()){
        while(index<n){
             v[index]=positive[i];
             i++;
             index++;
        }
    }
    else if(negative.size()>positive.size()){
        while(index<n){
             v[index]=negative[i];
             i++;
             index++;
        }
    }
    
    
}
