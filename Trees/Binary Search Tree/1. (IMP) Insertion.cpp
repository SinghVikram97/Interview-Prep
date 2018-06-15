https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

https://drive.google.com/open?id=1HTVm2ypB5lGvsyCmAs5-gGsJMX5SSh1H
https://drive.google.com/open?id=12RskIGXU9PoF1Wy0WiFK0O-XRLauUNQK

struct node* insert(struct node* node, int data)
{
    // Your code here
    
    /// Empty tree or reached to leaf node ka left or right
    if(node==NULL){
       return newNode(data);
    }
    else if(data<node->data){
        
        /// Insert new node to left and connect
        node->left=insert(node->left,data);
        
    }
    else if(data>node->data)
    {
        /// Insert new node to right and connect
        node->right=insert(node->right,data);
    }
    
    //Outside not inside both else if because we need this in equal to case
    // Duplicates not allowed so if data==node->data we just return that node
    return node;
    
}
