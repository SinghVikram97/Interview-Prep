https://practice.geeksforgeeks.org/problems/largest-bst/1

bool BST(Node *root,int min,int max){
    
    if(root==NULL){
        return true;  // leaf nodes both left and right subtree should be true
    }
    if(root->data<=min || root->data>=max){
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
int getSize(Node* node)
{
   if(node==NULL){
       return 0;
   }
   else{
       return 1+getSize(node->left)+getSize(node->right);
   }
}
int largestBst(Node *root)
{
    if(isBST(root)){
	    return getSize(root);
	}
	else{
	    return max(largestBst(root->left),largestBst(root->right));
	}
}
