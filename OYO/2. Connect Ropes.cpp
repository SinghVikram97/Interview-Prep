https://www.interviewbit.com/problems/connect-ropes-with-minimum-length/

int Solution::solve(vector<int> &A) {
    
    // At every step take shortest 2 ropes connect them and put them back
    priority_queue<int,vector<int>,greater<int> > pq;
    
    
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    
    int cost=0;
    
    while(pq.size()!=1){
        
        int a=pq.top();
        pq.pop();
        
        int b=pq.top();
        pq.pop();
        
        cost=cost+a+b;
        
        pq.push(a+b);
        
    }
    
    return cost;
}
