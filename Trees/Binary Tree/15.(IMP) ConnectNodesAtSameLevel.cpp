https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

https://drive.google.com/open?id=1sXZEW7OMJikwiQrjABIfd556CeU5-IN5 
https://drive.google.com/open?id=1pgw4C2QpCSQde-xMmlg2RMKy6dxYCLk8  (Correction of previous one)

void connect(Node *root)
{
   if(root==NULL){
       return;
   }
   queue<Node *> q;
   Node *prev=NULL;
   q.push(root);
   q.push(NULL);
   
   while(!q.empty()){
       
       Node *front=q.front();
       q.pop();
       
       if(prev==NULL){
           // Do nothing
       }
       else{
           prev->nextRight=front;
       }
       prev=front;
       
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
           }
       }
   }
}
