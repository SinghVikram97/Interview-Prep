https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

https://drive.google.com/open?id=1SdB9Q_HK-JBQ0rKBaNM0XwV0fA1kHrSl
https://drive.google.com/open?id=1slcNct1hcC7V5sVNxYbWEIoKEAMkVGWU

void bottomView(Node *root)
{
    unordered_map<int,vector<Node *> > hd;
    queue<pair<Node *,int> > q;
    q.push(make_pair(root,0));
    
    int min=0,max=0;
    
    while(!q.empty()){
        
        pair<Node *,int> front=q.front();
        q.pop();
        
        hd[front.second].push_back(front.first);
        
        if(front.second<min){
            min=front.second;
        }
        if(front.second>max){
            max=front.second;
        }
        if(front.first->left){
            q.push(make_pair(front.first->left,front.second-1));
        }
        if(front.first->right){
            q.push(make_pair(front.first->right,front.second+1));
        }
    }
    
    for(int i=min;i<=max;i++){
        
        // hd[i] is a vector print it's last element
        cout<<hd[i][hd[i].size()-1]->data<<" ";
        
    }
    
}
