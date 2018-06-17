https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

https://drive.google.com/open?id=1Fqf_Eu-3wz4pMY-r64ZpnbBu6najwKdG

Time Complexity of the above implementation is O(n) where n is number of nodes in given binary tree. 
The assumption here is that insert() and find() of unordered_set work in O(1)

void topView(struct Node *root)
{
    unordered_set<int> hd;
    
    // Store node and it's horizontal distance
    queue<pair<Node*,int> > q;
    
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        
        pair<Node *,int> front=q.front();
        q.pop();
        
        int hdFront=front.second;
        Node *temp=front.first;
        
        // See if this horizontal distance occurs 1st time
        if(hd.find(hdFront)==hd.end()){
            
            cout<<temp->data<<" ";
            
            // Insert in set, now no other node with same horizontal distance would be printed
            hd.insert(hdFront);
            
        }
        
        if(temp->left){
            q.push(make_pair(temp->left,hdFront-1));
        }
        
        if(temp->right){
            q.push(make_pair(temp->right,hdFront+1));
        }
    }
}
