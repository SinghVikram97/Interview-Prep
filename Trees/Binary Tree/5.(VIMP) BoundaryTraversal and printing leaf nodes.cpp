https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

https://www.youtube.com/watch?v=uemjIijtu2I

https://drive.google.com/open?id=1lIJWdgh9NPmr3vM7mXSC21eDlypG8hZF

void leftBoundary(Node *p){
    
    if(p!=NULL){
        
        // 1st try to move left
        if(p->left!=NULL){
            
            // To ensure top down order 1st print the node and then go down left or right
            cout<<p->data<<" ";
            leftBoundary(p->left);
        }
        // If can't move left
        else if(p->right!=NULL){
            cout<<p->data<<" ";
            leftBoundary(p->right);
        }
        
        // Otherwise it is a leaf node (BOTH NULL it returns back)
    }
    
}
void rightBoundary(Node *p){
    
    if(p!=NULL){
        
        if(p->right!=NULL){
            
            // To ensure bottom up manner 1st move right and print current node at last
            rightBoundary(p->right);
            cout<<p->data<<" ";
        }
        else if(p->left!=NULL){
            rightBoundary(p->left);
            cout<<p->data<<" ";
        }
        
        // Otherwise it is a leaf node (BOTH NULL it returns back)
    }
}

/// PRINTING LEAF NODES OF A TREE
void printLeafNodes(Node *root, Node *fixedRoot){
    
    if(root==NULL){
        return;
    }
    else if(root->left==NULL && root->right==NULL){
        if(root!=fixedRoot) {
            cout<<root->data<<" ";
        }
        return;
    }
    printLeafNodes(root->left,root);
    printLeafNodes(root->right,root);
}
void printBoundary(Node *root)
{
    
    if(root!=NULL){
        
        cout<<root->data<<" ";
        
        // Don't pass root to left and right boundary as it will be printed twice as it is in both boundaries
        leftBoundary(root->left);
        
        printLeafNodes(root,root);
        
        rightBoundary(root->right);
        
    }
     
}
