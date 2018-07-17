
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

https://drive.google.com/open?id=1SeNduBFT2Z0Z9OqOHxDaASpveYFPNg08

Node* reverse(Node *head)
{
  // Your code here
  
  Node *prev=NULL;
  Node *cur=head;
  Node *next=NULL;
  
  while(cur!=NULL){
      
      next=cur->next;
      cur->next=prev;
      prev=cur;
      cur=next;
      
  }
  return prev;  (IMP)
}
