https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

https://drive.google.com/open?id=1MFpK4yQfRl0JzJv6GabsIVhrywk6garB
https://drive.google.com/open?id=1W0D1M4XEY9xSwl0SY9FJHZW5OAmAu5vq

Now the problem is if we found an incorrect pair where prev.val > curr.val, 
how do we know which node is the incorrect one? The answer is it depends on whether we have found incorrect node before. 
So What is that?

Since we get two elements that are swapped by mistake, there must be a smaller TreeNode get a larger value and a 
larger TreeNode get a smaller value.
Their value are swapped, but the incorrect smaller node is still in smaller tree and incorrect
larger node is still in larger tree. So we will visit the incorrect smaller node first, and this 
node will be detected when we compare its value with next.val, i.e. when it is treated as prev node.
The incorrect larger node will be detected when we compare its value with prev.val. We don't know if
it is close or not close to incorrect smaller node, so we should continue search BST and update it if 
we found another incorrect node.

Therefore if it is the first time we found an incorrect pair, the prev node must be the first incorrect node.
If it is not the first time we found an incorrect pair, the curr node must be the second incorrect node, though
we may have corner case that two incorrect nodes are in same pair.

void inOrder(struct node* root,struct node *&prev, struct node *&first,struct node *&second){
    
    if(root==NULL){
        return;
    }
    
    // Search left tree
    inOrder(root->left,prev,first,second);
    
    //in inorder traversal of BST, prev should always have smaller value than current value
    if(prev!=NULL && prev->data>=root->data){
        
        //incorrect smaller node is always found as prev node
        if(first==NULL){
            first=prev;
        }
        //incorrect larger node is always found as curr(root) node
        second=root;
    }
    
    // Update prev node
    prev=root;
    
    // Search right subtree
    inOrder(root->right,prev,first,second);
}
struct node *correctBST( struct node* root )
{
    struct node* prev=NULL;
    struct node* first=NULL;
    struct node* second=NULL;
    
    inOrder(root,prev,first,second);
    
    // Swap values of first and second
    int temp=first->data;
    first->data=second->data;
    second->data=temp;
    
    return root;
    
}
