https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

https://drive.google.com/open?id=1LeCph_djnQox8dlBs7SeIIDcWYwlIhXV
https://drive.google.com/open?id=1IVHkCZATuQxM5l25EgsOToCa6BLA7sbP
https://drive.google.com/open?id=1k_pbPphcc4P_jZiZBziORLnl0TT5W1QX
https://drive.google.com/open?id=1lPT0CH5MOGEX53zU7OqsJYpMV30Qxi2d

O(N^2)

int height(Node* root)
{
   // Empty tree height is zero    
   if(root==NULL){
       return 0;
   }
   // Only one node or Leaf node height is one
   if(root->right==NULL && root->left==NULL){
       return 1;
   }
   
   int leftHeight=height(root->left);
   int rightHeight=height(root->right);
   
   // Height is 1+maximum depth we can go in left or right subtree
   
   return 1+max(leftHeight,rightHeight);
}
int diameter(Node* root)
{
   
   if(root==NULL){
       return 0;
   }
   if(root->left==NULL && root->right==NULL){
       return 0;
   }
   
   int leftDiameter=diameter(root->left);
   int rightDiameter=diameter(root->right);
   int diameterThroughRoot=1+height(root->left)+height(root->right);
   
   return max(diameterThroughRoot,max(leftDiameter,rightDiameter));
   
}
