https://practice.geeksforgeeks.org/problems/array-to-bst/0

Can be done same for sorted linked list. In linked list we find mid by fast slow technique

https://drive.google.com/open?id=1UALxrXlaHIRcZOCVkLmMk2eIhxbHCaeQ

// s=0, e=n-1
Node *sortedArrayToBst(int a[],int s,int e){
    
    
    if(s>e){
        return NULL;
    }
    
    int mid=(s+e)/2;
    
    int rootData=a[mid];
    
    int ls=s;
    int le=mid-1;
    
    int rs=mid+1;
    int re=e;
    
    Node *root=new Node;
    root->data=rootData;
    
    
    root->left=sortedArrayToBst(a,ls,le);
    root->right=sortedArrayToBst(a,rs,re);
    
    
    return root;
    
}
