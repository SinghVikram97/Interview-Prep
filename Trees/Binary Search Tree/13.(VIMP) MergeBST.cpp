

https://drive.google.com/open?id=1mh4W3GhL9QswAjRQs3rjDHc_52eMSUXD
https://drive.google.com/open?id=1XnTdbTjo3CptEMDLCSJaOrMjflO2FY_9



// 1. First, push all the elements from root to the left-most leaf node onto a stack. Do this for both trees 
// 2. Peek at the top element of each stack (if non-empty) and print the smaller one. 
// 3. Pop the element off the stack that contains the element we just print 
// 4. Add the right child of the element we just popped onto the stack, as well as all its left descendants

void insertNodes(Node *root,stack<Node *> &s){
    
    
    while(root!=NULL){
        s.push(root);
        root=root->left;
    }
    
}
void merge(Node *root1, Node *root2)
{
   stack<Node *> s1;
   stack<Node *> s2;
   
   // 1.First, push all the elements from root to the left-most leaf node onto a stack. Do this for both trees 
   insertNodes(root1,s1);
   insertNodes(root2,s2);
   
   while(!s1.empty() || !s2.empty()){
       
       // 2. Peek at the top element of each stack (if non-empty) and print the smaller one. 
       // If one the stack empty assign INT_MAX to value coming from that stack
       int a=(!s1.empty() ? s1.top()->data:INT_MAX);
       int b=(!s2.empty() ? s2.top()->data:INT_MAX);
       
       if(a<=b){
           cout<<a<<" ";
           Node *temp=s1.top();
           //3. Pop the element off the stack that contains the element we just printed
           s1.pop();
           //4. Add the right child of the element we just popped onto the stack, as well as all its left descendants
           insertNodes(temp->right,s1);
       }
       else{
           cout<<b<<" ";
           Node *temp=s2.top();
           //3. Pop the element off the stack that contains the element we just printed
           s2.pop();
           //4. Add the right child of the element we just popped onto the stack, as well as all its left descendants
           insertNodes(temp->right,s2);
           
       }
   }
}
