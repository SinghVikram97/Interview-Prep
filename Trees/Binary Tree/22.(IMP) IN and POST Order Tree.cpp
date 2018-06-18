https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

https://drive.google.com/open?id=1rUs2VasAQzKH5gTkQSiYU2UN5tTEDZwF

Node *buildTreeHelper(int in[],int post[],int inS,int inE,int postS,int postE){
    
    // Base case if empty array return NULL
    if(inS>inE){
        return NULL;
    }
    
    // Root ka data at end of post order
    int rootData=post[postE];
    
    // Find index of root ka data in indorder
    int rootIndex=-1;
    for(int i=inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    
    int lInS=inS;
    int lInE=rootIndex-1;
    int lPostS=postS;
    int lPostE=lInE-lInS+lPostS;
    
    int rInS=rootIndex+1;
    int rInE=inE;
    int rPostS=lPostE+1;
    int rPostE=postE-1;
    
    
    // Intialize new node and it's data as root ka data
    Node *root=new Node;
    root->data=rootData;
    
    // Connect left and right subtree
    root->left=buildTreeHelper(in,post,lInS,lInE,lPostS,lPostE);
    root->right=buildTreeHelper(in,post,rInS,rInE,rPostS,rPostE);
    
    // Return root
    return root;
    
}
Node *buildTree(int in[], int post[], int n)
{
    // Intially same start and end of both inorder and postorder
    return buildTreeHelper(in,post,0,n-1,0,n-1);
}
