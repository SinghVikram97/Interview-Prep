https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

https://drive.google.com/open?id=1zXvizBlLD5wUpZdeqT5GKdnrIEI2g2ud

Time complexity of above solution is O(h) where h is height of tree. Also, the above solution requires O(h) extra space in function call stack 

RECURSIVE

Node* LCA(Node *root, int n1, int n2)
{
    if(root==NULL){
       return NULL;
   }
   
   // Move left
   if(n1<root->data && n2<root->data){
       return LCA(root->left,n1,n2);
   }
   
   // Move right
   if(n1>root->data && n2>root->data){
       return LCA(root->right,n1,n2);
   }
   // Return root as n1<root->data<n2 or vice versa
   return root;
}

NON RECURSIVE

Node* LCA(Node *root, int n1, int n2)
{
   while(root!=NULL){
       
       if(n1<root->data && n2<root->data){
           root=root->left;
       }
       else if(n1>root->data && n2>root->data){
           root=root->right;
       }
       else{
            break;
       }
   }
   return root;
}
