https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

https://drive.google.com/open?id=1gDRkXDFuWoKiNvU6nWfzi4wyh5VZH9w5

void inorder(Node *root,vector<int> &v){
    
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
    
}
void merge(Node *root1, Node *root2)
{
   vector<int> v1;
   vector<int> v2;
   inorder(root1,v1);
   inorder(root2,v2);
   
   
   int n=v1.size();
   int m=v2.size();
   
   
   int i=0;
   int j=0;
   
   
    while(i<n && j<m){
       
      if(v1[i]<=v2[j]){
           
          cout<<v1[i]<<" ";
          i++;
      }
       
      else{
          cout<<v2[j]<<" ";
          j++;
      }
       
  }
   
  while(i<n){
      cout<<v1[i]<<" ";
      i++;
  }
  while(j<m){
      cout<<v2[j]<<" ";
      j++;
  }
   
   
   
}
