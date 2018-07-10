https://practice.geeksforgeeks.org/problems/wave-array/0

BY SORTING - IT PRINTS lexicographically smallest

https://drive.google.com/open?id=1DGbFZV9o6KAJquqdHBLXUAlWhoq8gN7S

void wavePrint(vector<int> &v,int n){
    
    sort(v.begin(),v.end());
    
    for(int i=0;i<=n-2;i=i+2){
        
        // swap(v[i+1],v[i]);
        cout<<v[i+1]<<" "<<v[i]<<" ";    
        
    }
    if(n%2!=0){
        cout<<v[n-1];
    }
    cout<<endl;
}


https://drive.google.com/open?id=15Cv5nJfa_6_4fnyzd8f5gMk6cJ5Q-HYM
https://drive.google.com/open?id=1GCddt7wd5_V_tSh-FTIsfcvpeq3eSB0R

Same question https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/

One of the possible answers in O(n) but not lexicographically smallest

void wavePrint(vector<int> &v,int n){
    
    for(int i=1;i<n;i=i+2){
        
        if(v[i]>v[i-1]){
            swap(v[i],v[i-1]);
        }
        if(i+1<n && v[i]>v[i+1]){
            swap(v[i],v[i+1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
