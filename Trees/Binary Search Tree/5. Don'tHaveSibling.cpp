https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

https://drive.google.com/open?id=1TyXBQyMmNGixfWkG3yfYiikWVxyWC_-v

void printSibling(Node* root)
{
   // Your code here
   if(root==NULL){
       return;
   }
   // Leaf node no children to check
   else if(root->left==NULL && root->right==NULL){
       return;
   }
   else if(root->left!=NULL && root->right!=NULL){
       printSibling(root->left);
       printSibling(root->right);
   }
   else if(root->left==NULL){
       cout<<root->right->data<<" ";
       printSibling(root->right);
   }
   else {
        cout<<root->left->data<<" ";
        printSibling(root->left);
   }
}
