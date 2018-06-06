
https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

https://drive.google.com/open?id=1gLAwREQOoEP3nkmte-YAzu3TgiV3Kn-a

void removeTheLoop(Node *head)
{
     //Your code here
     
     if(head==NULL){
         return;
     }
     else{
         
         Node *fast=head;
         Node *slow=head;
         
         while(fast->next!=NULL && fast->next->next!=NULL){
             
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow){
                
                Node *ptr1=head;
                Node *ptr2=slow;
                
                while(ptr1->next!=ptr2->next){
                    ptr1=ptr1->next;
                    ptr2=ptr2->next;
                }
                
                ptr2->next=NULL;
                return;
                
            }
            
         }
         return;
     }
}
