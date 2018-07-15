https://www.geeksforgeeks.org/delete-leaf-nodes-value-x/

/// Postorder traversal because
It must handle all cases for example if u delete both leaf from a node Say B. Then the node B also becomes the leaf node

Node *deleteLeafNodes(Node *root,int k){

    if(root==NULL){
        return NULL;
    }
    root->left=deleteLeafNodes(root->left,k);
    root->right=deleteLeafNodes(root->right,k);
    /// If root is a leaf node delete it
    if(root->data==k && root->left==NULL && root->right==NULL){
        delete(root);
        return NULL; /// For connecting back
    }   
    return root; /// For connecting back
}
