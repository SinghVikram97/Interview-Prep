https://practice.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

https://drive.google.com/open?id=19sdngW7ULKx-cRR9bQrre8iA9ur-7dsI

void sortedInsert(Node** head_ref, int x)
{
    Node *newNode=new Node;
    newNode->data=x;
    
   
   // 1. If linked list is empty
   if(*head_ref==NULL){
       
       newNode->next=newNode;
       *head_ref=newNode;
       
   }
   
   // 2. If x added to front of the list
   else if(x<(*head_ref)->data){
       
       // Find the last node
       Node *last;
       Node *temp=*head_ref;
       while(temp->next!=NULL){
           temp=temp->next;
       }
       last=temp;
       
       // Insert
       newNode->next=*head_ref;
       *head_ref=newNode;
       last->next=newNode;
   }
   
   // 3. x in middle or last
   Node *temp=(*head_ref)->next;
   Node *prev=*head_ref;  
   
   while(temp!=NULL && temp->data<x){
       
       prev=temp;
       temp=temp->next;
       
   }
   
   if(temp==NULL){
       // Insert at last
       prev->next=newNode;
       newNode->next=*head_ref;
   }
   else{
       // Insert in middle
       newNode->next=prev->next;
       prev->next=newNode;
   }
}
