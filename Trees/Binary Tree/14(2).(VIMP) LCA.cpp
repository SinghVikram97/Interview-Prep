https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

https://drive.google.com/open?id=1jyA9DxArKsemr6mw-m56AbSeZPOodhqZ
https://drive.google.com/open?id=1ipQY0m18vE8WAVkV5M0E3EFmV2N7Ko5_

Correction space compelexity is still O(height of the tree) due to recursive stack.

If you still don't understand
https://youtu.be/13m9ZCB8gjw

Doesn't work when n1 or n2 not present in the tree

Node * LCA(Node* root ,int n1 ,int n2 )
{
   if(root==NULL){
       return NULL;
   }
   // If data of root matches with n1 or n2
   if(root->data==n1 || root->data==n2){
       return root;
   }
   
   Node *left=LCA(root->left,n1,n2);
   Node *right=LCA(root->right,n1,n2);
   
   // 1. If we get not null from both side this current node is the lca return it
   if(left && right){
       return root;
   }
   // 2. If we get null from one side and a node from another return not null wali node
   if(left){
       return left;
   }
   if(right){
       return right;
   }
   
   // 3. If we get null from both sides return null
   return NULL;
   
}

