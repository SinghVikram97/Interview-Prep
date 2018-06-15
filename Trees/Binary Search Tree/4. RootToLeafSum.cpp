https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

https://drive.google.com/open?id=1Ek6QxfUYwcpGUxWWrGh-9VaDgMHkN5K6

bool hasPathSum(Node *root, int sum)
{
   
   // Empty tree
   if(root==NULL){
       return false;
   }
   // We have reached a leaf node with sum=value of that node
   else if(root->data==sum && root->right==NULL && root->left==NULL){
       return true;
   }
   else
   {
       if(hasPathSum(root->left,sum-root->data) || hasPathSum(root->right,sum-root->data)){
           return true;
       }
       else{
           return false;
       }
   }
}
