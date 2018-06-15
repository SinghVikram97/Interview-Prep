https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1

https://drive.google.com/open?id=15JIPE3MC77LdqGsnZ0_rsVTFLyGgdmzx
https://drive.google.com/open?id=16HxiiYypwYCFyenXCp9y8cpQgQehEwm1
https://drive.google.com/open?id=1kCmuWszD6-64vHK0guW4O47i8EdHTS0v
https://drive.google.com/open?id=1_GXYo24kRHVulBJQhCJUmZbdH_JUXCqg

Node *getMin(Node *cur){
    
    while(cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur;
    
}
Node * deleteNode(Node *root,  int x)
{
  // your code goes here   
  
  // Base case
  if(root==NULL){
      return root;
  }
  else if(x<root->data){
      root->left=deleteNode(root->left,x);  // delete ndoe returns new head even if it not changes
      // We don't return anything here we return root here as head doesn't change (At last)
  }
  else if(x>root->data){
      root->right=deleteNode(root->right,x);
       // We don't return anything here we return root here as head doesn't change (At last)
  }
   // key matches data value of node
  else{
      
     // Left child empty or no children(leaf node) 
     if(root->left==NULL){
          
          Node *temp=root->right;
          free(root);
          return temp;   // Temp(root->right) will get connected to the node which called node to be deleted
          // We return temp here as we can't return root as head has changed 
      }
     // Right child empty 
     else if(root->right==NULL){
         
         Node *temp=root->left;
         free(root);
         return temp;
         
         // We return temp here as we can't return root as head has changed
         
     } 
     // Both children
     else{
         Node *temp=getMin(root->right);  // Get minimum value in root->right 
         root->data=temp->data;
         root->right=deleteNode(root->right,temp->data); // Not x as x already replaced by temp->data
         // Now temp->data at 2 places in place of x and original place
         // Delete it from it's original place which will be found to right of root
         
          // We don't return anything here we return root here as head doesn't change (At last)
     } 
     return root;  
  }
}
