https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x/0

https://drive.google.com/open?id=1nKpidfF5HzLyxN3uMKP6T44xlNgaaXbo

void findPair(vector<int> &a,vector<int> &b,int n,int m,int k){
    
    vector<pair<int,int> > v;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    
    for(int i=0;i<m;i++){
        
        if(s.find(k-b[i])!=s.end()){
            v.push_back(make_pair(k-b[i],b[i]));
        }
        
    }
    
    if(v.size()==0){
        cout<<-1<<endl;
        return;
    }
    
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        
        cout<<v[i].first<<" "<<v[i].second;
        
        if(i!=v.size()-1){
            cout<<", ";
        }
        
        
    }
    cout<<endl;
}
