https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

https://drive.google.com/open?id=1OMcJBP3Eg7qm6DMbFPZdf93zhDaAXDX7
https://drive.google.com/open?id=1QyhxWEC_vKBvTpVV3EzV1OEosZNeY5q0

int getMiddle(Node *head)
{
   // Your code here
   
   if(head==NULL){
       return -1;
       
   }
   Node *slow=head;
   Node *fast=head;
   
//    while(fast->next!=NULL && fast->next->next!=NULL){
       
//        fast=fast->next->next;
//        slow=slow->next;
       
//    }
   while(fast!=NULL && fast->next!=NULL){
   
         slow=slow->next;
         fast=fast->next->next;
   
   }
   cout<<"Mid is :"<<slow->data;
   
//    // Odd elements
//    if(fast->next==NULL){
//        return slow->data;
//    }
//    // Even elements
//    else if(fast->next->next==NULL){
//        return slow->next->data;
//    }
}
