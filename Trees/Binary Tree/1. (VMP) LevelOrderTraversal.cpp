https://drive.google.com/open?id=1ZZTEaNzQKUFZIz4rDg1Zm0MFL7eE_qsa
https://drive.google.com/open?id=1bfs4W71yI55WHrKh11Ip_faXRhwvpLJ0

https://practice.geeksforgeeks.org/problems/level-order-traversal/1
In single line
void levelOrder(Node* root)
{
    if(root==NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        
        Node *front=q.front();
        q.pop();
        cout<<front->data<<" ";
        
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
}

https://practice.geeksforgeeks.org/problems/level-order-traversal-line-by-line/1
Line by line (VIMP)

void levelOrder(Node* root)
{
  if(root==NULL){
      return;
  }
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  
  while(!q.empty()){
      
      Node *front=q.front();
      q.pop();
      
      if(front!=NULL){
          cout<<front->data<<" ";
          if(front->left!=NULL){
              q.push(front->left);
          }
          if(front->right!=NULL){
              q.push(front->right);
          }
      }
      else{
          // Change in level
          cout<<'$'<<" ";
          // If queue becomes empty we don't need to push NULL as no nodes left to print
          if(!q.empty()){
              q.push(NULL); // Pichla level khtm aur unke saare children in queue toh unke children vala level khtm isliye NULL
          }
      }
      
  }
}



