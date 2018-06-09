https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

https://drive.google.com/open?id=1-npbFadf1BpNczoDbRIaBbQwidy1lEK_
https://drive.google.com/open?id=1iyEv71P0bhLv7IglEC6bx8nKOt9QP3FV

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
                prev->next=ptr1;
                
                
            }
            prev=ptr1;
            ptr1=ptr1->next;
        }
        else{
            
            if(prev==NULL){
                newHead=ptr2;
            }
            else{
                prev->next=ptr2;
            }
            prev=ptr2;
            ptr2=ptr2->next;
        }
        
    }
    while(ptr1!=NULL){
        prev->next=ptr1;
        prev=ptr1;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        prev->next=ptr2;
        prev=ptr2;
        ptr2=ptr2->next;
    }
    return newHead;
}
Node * mergeKList(Node *arr[], int N)
{
       int last=N-1;
       
       // Single list
       while(last!=0){
           
           int i=0,j=last;
           while(i<j){
               
               // Merge list i and list j and store in arr[i]
               arr[i]=merge(arr[i],arr[j]);
               // Choose next pair
               i++;
               j--;
               // If mid list(i=j) or all pairs merged(i>j)
               if(i>=j){
                   last=j;
               }
               
           }
       }
      return arr[0];
}
