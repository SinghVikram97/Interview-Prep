https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

https://drive.google.com/open?id=10m4QaToMx_6SskJ9Z5FStl7tBYJlyGnb
https://drive.google.com/open?id=13PTZEYZaI6143NQgL1wSsn-cvOahrraO

Node *removeDuplicates(Node *root)
{
 // your code goes here
    if(root==NULL){
        return root;
    }
 
 
   Node *cur=root;
   
   while(cur!=NULL && cur->next!=NULL){
       
       if(cur->next->data==cur->data){
           Node *temp=cur->next;
           cur->next=cur->next->next;
           delete temp;
       }
       else{
           cur=cur->next;
       }
   }
   return root;
 
 
}
