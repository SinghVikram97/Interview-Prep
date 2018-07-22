https://practice.geeksforgeeks.org/problems/check-for-bst/1

https://drive.google.com/open?id=1TIit8YaESfgL8FwXwBBWES40jPkcYJV3
https://drive.google.com/open?id=19WWYeixuIKct60yI-B5wdZuiigwjTLnX  (IMP)

bool BST(Node *root,int min,int max){
    
    if(root==NULL){
        return true;  // leaf nodes both left and right subtree should be true
    }
    if(!(root->data>min && root->data<max)){
        return false;
    }
    // Left jate ho toh upper limit cur node ka data hona chaiye
    // Right jate ho toh lower limit cur node ka data. Matlab cur node ke data se jyada hone chaiye 
    // Right mein
    return BST(root->left,min,root->data) && BST(root->right,root->data,max);

}   
bool isBST(Node* root) {
   return BST(root,INT_MIN,INT_MAX);
}
