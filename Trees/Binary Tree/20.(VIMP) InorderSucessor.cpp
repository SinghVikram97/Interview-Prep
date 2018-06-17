https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

https://drive.google.com/open?id=1HYiftyd-Bl7WmYZfnBajLEgQp06P1bst
https://drive.google.com/open?id=1toWNh21CTdLjVDvi0VNWkvXwbVlvm5jF
https://drive.google.com/open?id=18rnhVLMlX92upXzOeBm8EIe0-y-_KZUW
https://drive.google.com/open?id=16NhgXEtyU6A1QKj1bFt7-K6qb0dqDrRB

Node * inOrderSuccessor(Node *root, Node *x)
{
    Node *suc=NULL;

    while(root!=NULL){
        
        
        if(root->data==x->data){
            
            // See if it's right subtree exits
            if(root->right!=NULL){
            
                Node *temp=root->right;
            
                while(temp->left){
                  temp=temp->left;
                }
            
                // If temp->left is NULL ie. no leftmostmost child in rightsubtree
                // Then temp contains root of rightsubtree
                 suc=temp;
             }
             break;
        }
        // inOrderSuccessor means just next greater element because inOrder is sorted
        // So if you find any greater element store it and move towards target node
        else if(x->data<root->data){
            suc=root;
            root=root->left;
        }
        // Move towards target node
        else{
            root=root->right;
        }
    }
    return suc;
}
