https://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/

https://drive.google.com/open?id=1nwXUe543j1iz6VVnBKvxmu4M2SUOkpJs

Node *kAltReverse(Node *head, int k)
{
    if(head==NULL){
        return head;
    }
    // Head will change
    
    // 1. Reverse 1st k Nodes
    Node *prev=NULL;
    Node *cur=head;
    Node *next=NULL;
    int count=0;
    
    while(cur!=NULL && count<k){
        
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        count++;
        
    }
    
    // Now cur is at NULL or at (k+1)th node
    // 2. Connect head to (k+1)th node
    if(head!=NULL){
         head->next=cur;
    }
   
    // 3. Skip k-2 Nodes (Not k not k-1)
    count=0;
    while(cur!=NULL && count<k-1 ){
        cur=cur->next;
        count++;
    }
    
    // 4. Connect (2k)th node to newhead of reversed list returned by recursion
    if(cur!=NULL){
        cur->next=kAltReverse(cur->next,k);
    }
    

    // 5.return prev
    return prev;
    
}
