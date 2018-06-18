https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

https://drive.google.com/open?id=1YwrEmPaSEC16iWg7tINZ2JBmwbPAE6l_

void insertNodes(Node *root,stack<Node *> &s){
    
    while(root!=NULL){
        s.push(root);
        root=root->left;
    }
}
void BToDLL(Node *root, Node **head_ref)
{
    stack<Node *> s;
    insertNodes(root,s);
    Node *prev=NULL;
    while(!s.empty()){
        
        Node *temp=s.top();
        s.pop();
        
        // Create a newNode for linked list
        Node *newNode=new Node;
        newNode->data=temp->data;
        newNode->left=NULL;
        newNode->right=NULL;
        
        // First node in inorder traversal make it head
        // Set prev to newNode
        if(prev==NULL){
            *head_ref=newNode;
             prev=newNode;
        }
        else{
            prev->right=newNode;
            newNode->left=prev;
            prev=newNode;
        }
        
        insertNodes(temp->right,s);
    }
}
