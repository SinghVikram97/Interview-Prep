https://practice.geeksforgeeks.org/problems/k-distance-from-root/1

https://drive.google.com/open?id=1020JCEw5XxKu2BiKzun6DdtFleVMTINW

ITERATIVE

void printKdistance(Node *root, int k)
{
  int level=0;
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  
  while(!q.empty()){
      
      if(level==k){
              break;
          }
          
      Node *front=q.front();
      q.pop();
      
      if(front!=NULL){
          
          if(front->left){
              q.push(front->left);
          }
          if(front->right){
              q.push(front->right);
          }
      }
      else{
          if(!q.empty()){
              q.push(NULL);
              level=level+1;
          }
      }
  }
  while(q.front()!=NULL){
      cout<<q.front()->data<<" ";
      q.pop();
  }
  
}

RECURSION

void printKdistance(Node *root, int k)
{
   if(root==NULL){
       return;
   }
   if(k==0){
       cout<<root->data<<" ";
       return;
   }
   printKdistance(root->left,k-1);
   printKdistance(root->right,k-1);
}
