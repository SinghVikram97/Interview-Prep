https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

https://drive.google.com/open?id=1AQ8iHf7u6qzb5leQ-dcQd_DJTCGHfl5k

void bottomView(Node *root)
{
    unordered_map<int,vector<Node *> > hd;
    queue<pair<Node *,int> > q;
    q.push(make_pair(root,0));
    unordered_map<Node*,int> level;
    level[root]=0;
    
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
            level[front.first->left]=level[front.first]+1;
            q.push(make_pair(front.first->left,front.second-1));
        }
        if(front.first->right){
            level[front.first->right]=level[front.first]+1;
            q.push(make_pair(front.first->right,front.second+1));
        }
    }
    int l;
    for(int i=min;i<=max;i++){
        
        cout<<hd[i][hd[i].size()-1]->data<<" ";
        l=level[hd[i][hd[i].size()-1]];
        
        // If you find another node with same horizontal distance at same level print it       
        // We are starting from last as it is guaranteed last element must be printed ie. it's on lowest level at a given horizontal distance
        
        for(int j=hd[i].size()-2;j>=0;j--){
            if(level[hd[i][j]]==l){
                cout<<hd[i][j]->data<<" ";
            }
            else{
                break;
            }
        }
    }
}
