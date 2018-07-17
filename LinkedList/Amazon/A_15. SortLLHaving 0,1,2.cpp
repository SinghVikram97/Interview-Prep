https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

https://drive.google.com/open?id=1KGeRdfxkpWYBB6SksUuzTlqx5EG2cfFH

void sortList(Node *head)
{
   //Add code here
   
   if(head==NULL){
       return;
   }
   Node *temp=head;
   int count0=0,count1=0,count2=0;
   while(temp!=NULL){
       
       if(temp->data==0){
           count0++;
       }
       else if(temp->data==1){
           count1++;
       }
       else{
           count2++;
       }
       temp=temp->next;
   }
   temp=head;
   while(count0--){
       temp->data=0;
       temp=temp->next;
   }
   while(count1--){
       temp->data=1;
       temp=temp->next;
   }
   while(count2--){
       temp->data=2;
       temp=temp->next;
   }
   return;
}

