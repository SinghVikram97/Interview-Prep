https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

https://drive.google.com/open?id=1srgpsCxdhtkYM-AKxEeMJLtY54QJCd4i

int getNthFromLast(Node *head, int n)
{
       // Your code here
       
       if(head==NULL){
           return -1;
       }
       
       Node *temp=head;
       int length=0;
       
       while(temp!=NULL){
           length++;
           temp=temp->next;
       }
       if(n>length){
           return -1;
       }
       else{
           int steps=length-n;
           temp=head;
           while(steps--){
               temp=temp->next;
           }
           return temp->data;
       }
}
