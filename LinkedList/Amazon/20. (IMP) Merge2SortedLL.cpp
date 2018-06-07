https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

https://drive.google.com/open?id=1DzMdSGcfNUeqdivrbYeGhRHKYbWdqXj0

Node* SortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    
    Node *temp1=head1;
    Node *temp2=head2;
    Node *prev=NULL; // Last added element
    Node *newHead;
    
    
    while(temp1!=NULL && temp2!=NULL){
        
        
        if(temp1->data<=temp2->data){
            
            if(prev==NULL){
                
                prev=temp1;
                temp1=temp1->next;
                newHead=head1;
            }
            else{
                
                // Point last added element to current element
                prev->next=temp1;
                // Make last added element as this current element
                prev=temp1;
                // As it is added to new linked list move pointer further
                temp1=temp1->next;
                
            }
            
        }
        else{
            
            if(prev==NULL){
                
                prev=temp2;
                temp2=temp2->next;
                newHead=head2;
                
            }
            else{
                prev->next=temp2;
                prev=temp2;
                temp2=temp2->next;
            }
            
        }
        
    }
    while(temp1!=NULL){
        
        prev->next=temp1;
        prev=temp1;
        temp1=temp1->next;
        
    }
    while(temp2!=NULL){
        
        prev->next=temp2;
        prev=temp2;
        temp2=temp2->next;
        
    }
    return newHead;
}
