https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

https://drive.google.com/open?id=1M4SIcyc-8hANB4TwrBszeYeOILzcbRKa

void pairWiseSwap(struct node *head)
{
   // The task is to complete this method
   if(head==NULL){
       return;
   }
   
   node *cur=head;
   while(cur!=NULL && cur->next!=NULL){
       int temp=cur->data;
       cur->data=cur->next->data;
       cur->next->data=temp;
       cur=cur->next->next;
   }
   return;
}
