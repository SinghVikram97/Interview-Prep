https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1

https://drive.google.com/open?id=1GfD2XEEckayfKBwjn6qINbNZD3frer_M
https://drive.google.com/open?id=1MBiT3KP1Szunok135F4Xkje4Ux2ZAecp

Node *rearrangeEvenOdd(Node *head)
{
   if(head==NULL || head->next==NULL || head->next->next==NULL){
       return head;
   }
   else{
       Node *odd=head;
       Node *even=head->next;
       Node *evenHead=even;
       
       // even=NULL in case of odd length and even->next=NULL in case of even length
       while(even!=NULL && even->next!=NULL){
           
           odd->next=even->next;  // Attach next odd
           odd=even->next;  // Make next odd as new odd
           
           even->next=odd->next; 
           even=odd->next;
           
       }
       odd->next=evenHead;
       return head;
       
   }
   
