https://practice.geeksforgeeks.org/problems/remove-every-kth-node/1

https://drive.google.com/open?id=1JDrqE0292Q2INw4KNqaZ2aYzFAiaUtQN

Node * deleteK(Node *head,int k)
{
  if(head==NULL){
      return head;
  }
  else if(k==0){
      return head;
  }
  else if(k==1){
      return NULL;
  }
  //Your code here
  // K>=2 Head doesn't change
  int count=1;
  Node *cur=head;
  Node *prev=NULL;
  
  while(cur!=NULL){
      
      if(count<k){
          prev=cur;
          cur=cur->next;
          count++;
      }
      // Count==k
      else{
          Node *temp=cur;
          prev->next=cur->next; // Prev can't be null as k>=2
          delete temp;
          // Prev name
          cur=prev->next;
          count=1;
      }
      
  }
  return head;
  
}
