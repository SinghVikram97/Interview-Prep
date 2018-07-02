https://practice.geeksforgeeks.org/problems/check-if-array-contains-contiguous-integers-with-duplicates-allowed/0


Visited array -> https://drive.google.com/open?id=1Ikc28m9boFzhjzx-0cUrRD7UAV63G1mH
...............................
bool isContiguous(vector<int> &v){
    int n=v.size();
    
    int minElement=INT_MAX;
    int maxElement=INT_MIN;
    
    for(int i=0;i<n;i++){
        minElement=min(v[i],minElement);
        maxElement=max(maxElement,v[i]);
    }
    
    vector<bool> isPresent(maxElement-minElement+1);
    
    for(int i=0;i<n;i++){
        isPresent[v[i]-minElement]=true;
    }
    
    for(int i=0;i<isPresent.size();i++){
        if(!isPresent[i]){
            return false;
        }
    }
    return true;
}

Unordered_set--> https://drive.google.com/open?id=1XToaaMrdhrUL3oMxZYD4VqHmaufHmlMg
...............................
bool isContiguous(vector<int> &v){
   
    int n=v.size();
    
    // Insert all elements in a unordered_set
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(v[i]);
    }
    
    // Include 1st element in count ie v[0]
    int count=1;
    
    // Other elements can be greater than v[0]
    int cur_ele=v[0]+1;
    
    while(s.find(cur_ele)!=s.end()){
        count++;
        cur_ele++;
    }
    
    // Or less than v[0]
    cur_ele=v[0]-1;
    
    while(s.find(cur_ele)!=s.end()){
        count++;
        cur_ele--;
    }
   
    // See if count of elements equal to size of set
    if(count==s.size()){
        return true;
    }
    else{
        return false;
    }
}
