https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

https://drive.google.com/open?id=1GanXKaEMlSGMG6ew6_5LQBW3U8fi2VnL  /// Hashing extra space is used
https://drive.google.com/open?id=1kWlr_KNko2NPvumynHVCybCtzaB9gVSP  /// No extra space



int detectloop(Node *head)
{
   // your code here
   Node *slow=head;
   Node *fast=head;
   
   while(fast->next!=NULL && fast->next->next!=NULL){
       
       fast=fast->next->next;
       slow=slow->next;
       
       if(fast==slow){
           return 1;
       }
       
   }
   return 0;
}
