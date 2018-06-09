https://practice.geeksforgeeks.org/problems/modify-linked-list-1/1

https://drive.google.com/open?id=15rxnn1lGC1ChfppEqKbyW6OTPNrrlS6i

struct Node* modifyTheList(struct Node *head)
{
    // See last comment on question that's why
    // Node *p=NULL;
    // Node *c=head;
    // Node *n=NULL;
    
    // while(c!=NULL){
    //     n=c->next;
    //     c->next=p;
    //     p=c;
    //     c=n;
    // }
    
    // head=p;
    
    //add code here.
    // 1. Find length of linked list
    Node *temp=head;
    int length=0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    
    // 2. Find mid by fast slow technique
    Node *fast=head;
    Node *slow=head;
    
    while(fast!=NULL && fast->next!=NULL){
        
        fast=fast->next->next;
        slow=slow->next;
        
    }
    cout<<slow->data<<endl;
    
    // 3. Reverse the list starting from mid in odd case and from mid in even case
    Node *prev=NULL;
    Node *cur=slow;
    Node *next=NULL;
    
    while(cur!=NULL){
        
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }

    // Prev is the new head of reversed list
    // while(prev){
    //     cout<<prev->data<<"-->";
    //     prev=prev->next;
    // }
    // cout<<endl;
    
    Node *ptrF=head;
    Node *ptrB=prev;
    int l=length/2;
    
    // 4. Substract front list from back reversed list
    while(l--){
        ptrF->data=ptrB->data-ptrF->data;
        ptrF=ptrF->next;
        ptrB=ptrB->next;
    }
    
    //5 . Again reverse the list with head as prev
    cur=prev;
    prev=NULL;
    next=NULL;
    
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    
    
    
    return head;
}
