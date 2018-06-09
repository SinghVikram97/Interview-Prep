https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

https://drive.google.com/open?id=1-eMX0NDELLvSWeb6G3oSS0S7fszU5pEg

Node *merge(Node *head1,Node *head2){
    
    if(head1==NULL){
        return head2;
    }
    else if(head2==NULL){
        return head1;
    }
    Node *prev=NULL;
    Node *ptr1=head1;
    Node *ptr2=head2;
    Node *newHead=NULL;
    
    while(ptr1!=NULL && ptr2!=NULL){
        
        if(ptr1->data<=ptr2->data){
            if(prev==NULL){
                
                newHead=ptr1;
                
            }
            else{
                // Changing bottom pointers
                prev->bottom=ptr1;
                
                
            }
            prev=ptr1;
            ptr1=ptr1->bottom;
        }
        else{
            
            if(prev==NULL){
                newHead=ptr2;
            }
            else{
                prev->bottom=ptr2;
            }
            prev=ptr2;
            ptr2=ptr2->bottom;
        }
        
    }
    while(ptr1!=NULL){
        prev->bottom=ptr1;
        prev=ptr1;
        ptr1=ptr1->bottom;
    }
    while(ptr2!=NULL){
        prev->bottom=ptr2;
        prev=ptr2;
        ptr2=ptr2->bottom;
    }
    return newHead;
}
Node *flatten(Node *root)
{
   // Your code here
   // If root->next is NULL it means only one list
   if(root==NULL || root->next==NULL){
       return root;
   }
   return merge(root,flatten(root->next));
}
