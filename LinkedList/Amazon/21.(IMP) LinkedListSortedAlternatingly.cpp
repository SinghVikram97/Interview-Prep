https://practice.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

https://drive.google.com/open?id=1sj3SwRFFb9aGrWA0N-N3_nFuj8UOLOM3

void sort(Node **head)
{
    // Seg fault for one element 
     if(*head==NULL || (*head)->next==NULL){
         return;
     }
     
     // 1. Seperate 2 lists as in odd even seperation question
     Node *odd=*head;
     Node *even=(*head)->next;
     Node *evenHead=even;
     
     while(even!=NULL && even->next!=NULL){
         
         odd->next=even->next; // Even ka next is odd
         odd=even->next;
         
         even->next=odd->next;
         even=odd->next;
         
     }
     
     odd->next=NULL;
     
    // We have 2 list  1st with head=head and second with head=evenHead
    
    //  Node *temp1=*head;
    //  Node *temp2=evenHead;
     
    //  while(temp1!=NULL){
    //      cout<<temp1->data<<" ";
    //      temp1=temp1->next;
    //  }
    //  cout<<endl;
     
    //  while(temp2!=NULL){
    //      cout<<temp2->data<<" ";
    //      temp2=temp2->next;
    //  }
    //  cout<<endl;
     
    //2. Reverse 2nd List 
    Node *prev=NULL;
    Node *cur=evenHead;
    Node *next=NULL;
    
    while(cur!=NULL){
        
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        
    }
    
    // New head of 2nd list is prev
    
    // Node *temp=prev;
    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    // cout<<endl;
    
    // 3. Merge 2 sorted linked list with heads as 1. head and 2. prev
    
    Node *temp1=*head;
    Node *temp2=prev;
    Node *lastAdded=NULL; // Last added element
    Node *newHead;
    
    
    while(temp1!=NULL && temp2!=NULL){
        
        
        if(temp1->data<=temp2->data){
            
            if(lastAdded==NULL){
                
                // No element added till now
                lastAdded=temp1;
                temp1=temp1->next;
                // 1st element added from list 1 so make it newHead;
                newHead=*head;
            }
            else{
                
                // Point last added element to current element
                lastAdded->next=temp1;
                // Make last added element as this current element
                lastAdded=temp1;
                // As it is added to new linked list move pointer further
                temp1=temp1->next;
                
            }
            
        }
        else{
            
            if(lastAdded==NULL){
                
                lastAdded=temp2;
                temp2=temp2->next;
                newHead=prev;
                
            }
            else{
                lastAdded->next=temp2;
                lastAdded=temp2;
                temp2=temp2->next;
            }
            
        }
        
    }
    while(temp1!=NULL){
        
        lastAdded->next=temp1;
        lastAdded=temp1;
        temp1=temp1->next;
        
    }
    while(temp2!=NULL){
        
        lastAdded->next=temp2;
        lastAdded=temp2;
        temp2=temp2->next;
        
    }
    *head=newHead;
}
