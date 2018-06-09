O(1) space

https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

https://drive.google.com/open?id=184yTMJsO-Tn5paAIE02Regb43VF1XwrJ
https://drive.google.com/open?id=1svHTpPN7L-ONjM7vXAbSBjLJXz2xWfsj

Node * copyList(Node *head)
{
    if(head==NULL){
        return head;
    }
     
    // 1. Insert clone 1 b/w original 1 and 2. clone 2 b/w original 2 and 3 and so on.
    Node *temp=head;
    Node *next=NULL;
    
    while(temp!=NULL){
        
        Node *newNode=new Node;
        newNode->data=temp->data;
        
        next=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
        temp=next;
        
    }
    
    // 2. Fix random pointer of cloned list
    Node *original=head;
    while(original!=NULL){
        
        if(original->arb!=NULL){
            original->next->arb=original->arb->next;
        }
        else{
            original->next->arb=NULL;
        }
        
       original = original->next->next;
    }
    
    // 3. Obtain original and cloned list
    original=head;
    Node *cloneHead=head->next; // IMP
    Node *clone=head->next;
    while(original->next->next!=NULL){
        
        original->next=original->next->next;
        clone->next=clone->next->next;
        original=original->next;
        clone=clone->next;
       
    }
    original->next=NULL;
    return cloneHead;
 
}
