https://drive.google.com/open?id=1ndWAR0w_BAltH9yQic8qJedse2SjPlEC

struct Node
{
    int data;
    Node* left;
    Node* right;
};

void inOrder(Node* root)
{
  // Your code here
  
  if(root==NULL){
      return;
  }
  
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
  
}

void preorder(Node* root)
{
  if(root==NULL){
      return;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postOrder(Node* root)
{
  if(root==NULL){
      return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}
