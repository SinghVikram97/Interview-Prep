https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

https://drive.google.com/open?id=1U0qjg5VVhRUMhFoRBYEcKR6sbTIm80mG

void leftView(Node *root)
{
   if(root==NULL){
       return;
   }
   
   queue<Node *> q;
   q.push(root);
   q.push(NULL);
   bool prevNull=true;
   
   while(!q.empty()){
       
       Node *front=q.front();
       q.pop();
      
       
       if(front!=NULL){
           
            if(prevNull){
               cout<<front->data<<" ";
           }
           prevNull=false;  // Irrespective ki push kiya ki nhi set prevNull=false
           
           if(front->left!=NULL){
               q.push(front->left);
           }
           if(front->right!=NULL){
               q.push(front->right);
           }
           
       }
       else{
           
           if(!q.empty()){
               q.push(NULL);
               prevNull=true;
           }
           
       }
   }
   
   
}
