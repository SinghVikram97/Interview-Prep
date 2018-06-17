https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

We can print spiral order traversal in O(n) time and O(n) extra space

https://drive.google.com/open?id=1EGO5oCtiZ2MiJdV8ThlY7vHRaFEygtcu

void printSpiral(Node *root)
{
     if(root==NULL){
         return;
     }
     stack<Node *> s1;  // Right to left
     stack<Node *> s2;  // Left to right
     
     s1.push(root);
     
     // Or not and
     // If both empty it means level order finished
     while(!s1.empty() || !s2.empty()){
         
         while(!s1.empty()){
             
             Node *top=s1.top();
             s1.pop();
             
             cout<<top->data<<" ";
             
             // Push to s2
             // Push top->right first and top->right last as we want to print left to right in s2
             // So left should be on top
             
             if(top->right){
                 s2.push(top->right);
             }
             if(top->left){
                 s2.push(top->left);
             }
             
         }
         while(!s2.empty()){
             
             Node *top=s2.top();
             s2.pop();
             
             cout<<top->data<<" ";
             
             
             // Push to s1
             // Push top->left first and top->right last as we want to print right to left in s2
             // So right should be on top
             if(top->left){
                 s1.push(top->left);
             }
             if(top->right){
                 s1.push(top->right);
             }
         }
     }
}
