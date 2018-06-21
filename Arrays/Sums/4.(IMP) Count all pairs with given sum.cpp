https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum/0

https://drive.google.com/open?id=17keR3ZcGFN42FnNqpCStKGwc44-guQsB
https://drive.google.com/open?id=1lkFUk15EeTjrcc93ZEUh4h_fuDPX8bJ_

int countPairs(vector<int> &v,int n,int k){
    
    // maps value to its freq  val-->freq
    unordered_map<int,int> myMap;
    int count=0;
    
    for(int i=0;i<n;i++){
        
        // Find it's counterpart and if found count=count+ freq of it's counterpart
        if(myMap.find(k-v[i])!=myMap.end()){
            count+=myMap[k-v[i]];
        }
        
        // Increase freq of current number in map
        myMap[v[i]]++;
        
    }
    return count;
}
