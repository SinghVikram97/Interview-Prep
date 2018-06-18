https://practice.geeksforgeeks.org/problems/construct-tree-1/1

https://drive.google.com/open?id=17RhjbHHEURtcP-8zt7jfCV3LufZB0Z4B
https://drive.google.com/open?id=14NRYyHix3VbVVA-16YwOzSYCzC5a7IoO

If still don't understand then only watch this video

https://www.youtube.com/watch?v=W9irlUOf6lI

Node *buildTreeHelper(int in[],int pre[],int inS,int inE,int preS,int preE){
    
    // Base case if empty array
    if(inS>inE){
        return NULL;
    }
    
    // root ka data will be at starting of preOrder
    int rootData=pre[preS];
    
    // Find root index in inOrder traversal
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    
    // We need eight variable
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPreS=preS+1;
    
    // Same number of elements in inorder and preorder of left so
    // lInE-lInS=lPreE-lPreS
    // So
    
    int lPreE=lInE-lInS+lPreS;
    
    int rInS=rootIndex+1;
    int rInE=inE;
    int rPreS=lPreE+1;
    int rPreE=preE;
    
    // Build the root node
    Node *root=new Node;
    // Root is at starting of preOrder
    root->data=rootData;
    // Attach left and right subtrees by recursion
    root->left=buildTreeHelper(in,pre,lInS,lInE,lPreS,lPreE);
    root->right=buildTreeHelper(in,pre,rInS,rInE,rPreS,rPreE);
    
    // Return root
    return root;
    
}
Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
    // Intially inStrt will be 0 and inEnd will be n-1
    // So we pass n-1
    // ie. Size-1 (inEnd)
    return buildTreeHelper(in,pre,0,inEnd,0,inEnd);
}
