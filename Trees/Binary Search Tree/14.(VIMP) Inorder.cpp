https://practice.geeksforgeeks.org/problems/inorder-traversal/1

https://drive.google.com/open?id=1kZggkvK7btRCZpsE6QoMkj6RkC288XQU

void insertNodes(Node *root,stack<Node *> &s){
    
    while(root!=NULL){
        s.push(root);
        root=root->left;
    }
    
}
void inOrder(Node* root)
{
   stack<Node *> s;
   insertNodes(root,s);
   
   
   while(!s.empty()){
       
       Node *temp=s.top();
       s.pop();
       cout<<temp->data<<" ";
       insertNodes(temp->right,s);
   }
}
