https://practice.geeksforgeeks.org/problems/delete-keys-in-a-linked-list/1

https://drive.google.com/open?id=1GOmo7_OMpo-x7RQ_eaLrrLMBiKvyLC7H

Node* deleteAllOccurances(Node *head,int x)
{
    //Your code here
    // Head can change
    
    if(head==NULL){
        return head;
    }
    
    Node *prev=NULL;
    Node *cur=head;
    
    while(cur!=NULL){
        
        
        if(cur->data!=x){
            prev=cur;
            cur=cur->next;
        }
        else{
            
            
            // If prev is NULL means matching element at head (Head will change)
            if(prev==NULL){
                Node *temp=head;
                head=head->next;
                cur=head;
                delete temp;
                // Prev will remain NULL
            }
            else{
                Node *temp=cur;
                prev->next=cur->next;
                cur=prev->next;
                // Prev remains same
                delete temp;
            }
            
            
        }
        
        
    }
    
    
    return head;
    
}
