https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

https://drive.google.com/open?id=1My5BOXmajLkHgI1H5NOAJbvgdowMgtnf

pair<int,int> maxSum(Node *root){
    
    if(root==NULL){
        return make_pair(0,0);
    }
    
    pair<int,int> l=maxSum(root->left);
    pair<int,int> r=maxSum(root->right);
    
    // Root to leaf sum can be from current node to it's left subtree leaf node
    // Or it can be from current node to it's right subtree leaf node
    int rootToLeaf=root->data+max(l.first,r.first);
    
    // Max sum has 3 options 
    // Max sum of leaf of left through root to leaf of right
    int maxSum=root->data+l.first+r.first;
    
    // Or max sum in left or right subtree
    maxSum=max(maxSum,max(l.second,r.second));
    
    return make_pair(rootToLeaf,maxSum);
    
}
int maxPathSum(struct Node *root)
{
   pair<int,int> p=maxSum(root);
   return p.second;
}
