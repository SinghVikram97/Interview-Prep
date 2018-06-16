https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1


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
