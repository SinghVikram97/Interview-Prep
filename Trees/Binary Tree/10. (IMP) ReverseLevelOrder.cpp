https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

https://drive.google.com/open?id=11IBsYTuzEYQ5yYIlosWWf4qKk1bzg_Ge

void reversePrint(Node *root)
{
   
   queue<Node *> q;
   vector<int> v;
   q.push(root);
   
   while(!q.empty()){
       
       Node *front=q.front();
       q.pop();
       
       v.push_back(front->data);
       
       if(front->right){
           q.push(front->right);
       }
       if(front->left){
           q.push(front->left);
       }
       
   }
   for(int i=v.size()-1;i>=0;i--){
       cout<<v[i]<<" ";
   }
}
