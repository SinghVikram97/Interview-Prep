https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/

https://drive.google.com/open?id=1M72FbEN7PNUbslB_SC0-5c5ftprPbVDE

https://drive.google.com/open?id=1hsbVSNmMBnNSRLGyMiOSIQZBCWDXXjuH (BETTER METHOD)

int Lca(Node *root,int a,int b){
    
    if(root==NULL){
        return -1;
    }
    
    if(root->data==a){
        return a;
    }
    if(root->data==b){
        return b;
    }
    
    int left;
    int right;
    
    left=Lca(root->left,a,b);
    right=Lca(root->right,a,b);
    
    if(left!=-1 && right!=-1){
        return root->data;
    }
    if(left!=-1){
        return left;
    }
    if(right!=-1){
        return right;
    }
    
    // Else both left and right -1
    return -1;
}
int distFromRoot(Node *root,int key){
    
    if(root==NULL){
        return -1;
    }
    // Zero distance
    if(root->data==key){
        return 0;
    }
    
    int leftDist=distFromRoot(root->left,key);
    
    // If key present in left subtree then it must return a distance>=0
    if(leftDist>=0){
        return leftDist+1;
    }
    else{
        // If not search in right subtree
        int rightDist=distFromRoot(root->right,key);
        // If present return dist+1
        if(rightDist>=0){
            return rightDist+1;
        }
        // Key doesn't exist in the tree
        else{
            return -1;
        }
    }
}
int findDist(Node* root, int a, int b)
{
    int LCA=Lca(root,a,b);
    int dist1=distFromRoot(root,a);
    int dist2=distFromRoot(root,b);
    int dist3=distFromRoot(root,LCA);
    
    return dist1+dist2-(2*dist3);
}
