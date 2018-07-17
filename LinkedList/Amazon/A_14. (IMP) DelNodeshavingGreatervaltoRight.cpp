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
     
     Node *newHead=prev;
     int maxTillNow=newHead->data;
     cur=newHead->next; // Start traversing from 2nd element as head doesn't have any element to left
     prev=newHead;
     
     while(cur!=NULL){
         // It means a greater element to left
         if(cur->data<maxTillNow){
             // Delete it
             Node *temp=cur;
             prev->next=cur->next;
             delete temp;
             cur=prev->next; // Prev remains same
         }
         else{
             // Update maxTillNow
             maxTillNow=cur->data;
             prev=cur;
             cur=cur->next;
         }
     }
     
     
     
     // 3. Reverse the list again
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

