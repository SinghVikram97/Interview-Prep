https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1


https://drive.google.com/open?id=186iLt3vxtj4zk1k0x2g0j2ekNkTRQSdF
https://drive.google.com/open?id=1A0y_Q5wX9_AJloBpt1hwo9_G3iZDczbu

https://www.youtube.com/watch?v=PQKkr036wRc&t=581s

USING MAP TIME COMPLEXITY-O(nlogn)
void verticalOrder(Node *root)
{
    map<int,vector<Node *> > hd;
    queue<pair<Node *,int> > q;
    
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        
        pair<Node *,int> front=q.front();
        q.pop();
        
        // Update the map by adding a node with horizontal distance of front.second
        hd[front.second].push_back(front.first);
        
        // Push children of front with left child hd as front.second-1 and right child
        // hd as front.second+1
        
        if(front.first->left){
            q.push(make_pair(front.first->left,front.second-1));
        }
        if(front.first->right){
            q.push(make_pair(front.first->right,front.second+1));
        }
    }
   
    for(auto it=hd.begin();it!=hd.end();it++){
       
       for(int i=0;i<it->second.size();i++){
           cout<<it->second[i]->data<<" ";
       }
       cout<<"$";
    }
}


Using unordered_map TIME COMPLEXITY-O(N) 

void verticalOrder(Node *root)
{
    unordered_map<int,vector<Node *> > hd; // Maps horizontal distance to a list of nodes
    queue<pair<Node *,int> > q;  // Stores a node and it's horizontal distance
    
    q.push(make_pair(root,0));  // Root at zero horizontal distance (origin)
    
    int max=0,min=0;   // Maximum and minimum horizontal distance
     
    while(!q.empty()){
        
        pair<Node *,int> front=q.front();
        q.pop();
        
        // Update the map by adding a node with horizontal distance of front.second
        hd[front.second].push_back(front.first);
        
        // Update max and minimum distance
        if(front.second>max){
            max=front.second;
        }
        if(front.second<min){
            min=front.second;
        }
        
        // Push children of front with left child hd as front.second-1 and right child
        // hd as front.second+1
        
        if(front.first->left){
            q.push(make_pair(front.first->left,front.second-1));
        }
        if(front.first->right){
            q.push(make_pair(front.first->right,front.second+1));
        }
    }
   
    for(int i=min;i<=max;i++){
        
        // hd[i] gives a vector of nodes with horizontal distance of i
        for(int j=0;j<hd[i].size();j++){
            cout<<hd[i][j]->data<<" ";
        }
        cout<<"$";
    }
}
