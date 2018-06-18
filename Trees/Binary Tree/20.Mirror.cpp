https://practice.geeksforgeeks.org/problems/two-mirror-trees/1

https://drive.google.com/open?id=12KJR6IPCOUFYEsY7JIQooBpnTjuEtU5a

int areMirror(Node* a, Node* b)
{
   if(a==NULL && b==NULL){
       return 1;
   }
   if(a==NULL || b==NULL){
       return 0;
   }
   if(a->data==b->data){
       
       if(areMirror(a->left,b->right) && areMirror(a->right,b->left)){
           return 1;
       }
       else{
           return 0;
       }
       
   }
   else{
       return 0;
   }
}
