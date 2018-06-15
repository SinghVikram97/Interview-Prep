https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

https://drive.google.com/open?id=1sxBJrSUHwBoof_nbyoVrUkrSx0cCf3pV

void rightView(Node *root)
{
   // Your Code here
   if(root==NULL){
       return;
   }
   queue<Node *> q;
   q.push(root);
   q.push(NULL);
   
   
   int prevElementPushed;
   
   while(!q.empty()){
       
       Node *front=q.front();
       q.pop();
       
       if(front!=NULL){
           
           prevElementPushed=front->data;
           
           if(front->left!=NULL){
               q.push(front->left);
           }
           if(front->right!=NULL){
               q.push(front->right);
           }
           
           
       }
       else{
           
           if(!q.empty()){
               cout<<prevElementPushed<<" ";
               q.push(NULL);
           }
           
       }
   }
   cout<<prevElementPushed;
}
