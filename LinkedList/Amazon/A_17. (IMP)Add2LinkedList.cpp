https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

https://drive.google.com/open?id=1OfAlBxPgnT2kh6PptbuiEIhsN7wCYkeX
https://drive.google.com/open?id=1RHgLgjD8RQd7sDwoQhU6bOiq7q2m-SlO
https://drive.google.com/open?id=1Pf3gN5YUOUb62qJ55qOPd-XXrsiH3zzr

//Leetcode
https://drive.google.com/open?id=1OgOAb48NQJfvn0R8YYc8euAPTYIA0fd1 (See in IMP questions using 2 stacks)

void addBack(Node *&head,Node *&last,int data){
   
   Node *newNode=new Node;
   newNode->data=data;
   newNode->next=NULL;
   
   if(last==NULL){
       head=newNode;
   }
   else{
       last->next=newNode;
   }
   last=newNode;
   
}
Node*  addTwoLists(Node* first, Node* second){
    
  Node *head1=first;
  Node *head2=second;
  Node *head3;
  Node *last=NULL; // Last node of new list
  int total,carry=0;
  // One of them not NULL
  while(head1|| head2){
      
      int a=(head1)?(head1->data):(0); // If NULL contri is 0
      int b=(head2)?(head2->data):(0);
      
      total=(a+b+carry);
      carry=(total/10);
      total=total%10;
      
      // Add this to back of new list
      addBack(head3,last,total);
      
      if(head1){
          head1=head1->next;
      }
      
      if(head2){
           head2=head2->next;
      }
  }
  if(carry!=0){
      addBack(head3,last,carry);
  }
  return head3;
}
