https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

https://drive.google.com/open?id=1dsmOMT7YTRnHqKLNkwAn57qBzbBqkDFq
https://drive.google.com/open?id=19Ee1VZZnFVc5bHhGWFiIBLf3QWSQb2UA
https://drive.google.com/open?id=1BYThz_or33xg_YcpHOISpZ-LiZ14WUfH

Node *compute(Node *head)
{
// your code goes here
    
    // 1. Reverse the list
     Node *prev=NULL;
     Node *cur=head;
     Node *next=NULL;
     
     while(cur!=NULL){
         
         next=cur->next;
         cur->next=prev;
         prev=cur;
         cur=next;
         
     }
     
     // 2. Start traversing reversed list now we have to delete elements having greater elements to left
     
     Node *temp=prev; // Prev is the newHead
     Node *maxTillNow=prev;  // So that we know if there's a element greater to left
     
     while(temp->next!=NULL){
         
         if(temp->next->data<maxTillNow->data){
             
             // Delete temp->next
             Node *del=temp->next;
             temp->next=temp->next->next;
             delete del;
             // No need to do temp=temp->next as temp->next already got updated
         }
         else{
             
             // Update max
             maxTillNow=temp->next;  // Not temp as we are comparing temp->next->data
             temp=temp->next;
             
         }
         
     }
     
     // 3. Reverse the list again
     Node *newHead=prev;
     prev=NULL;
     cur=newHead;
     next=NULL;
     
     while(cur!=NULL){
         
         next=cur->next;
         cur->next=prev;
         prev=cur;
         cur=next;
         
     }
     return prev;
     
}
