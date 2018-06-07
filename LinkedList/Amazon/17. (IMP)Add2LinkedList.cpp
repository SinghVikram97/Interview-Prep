https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

https://drive.google.com/open?id=1OfAlBxPgnT2kh6PptbuiEIhsN7wCYkeX
https://drive.google.com/open?id=1RHgLgjD8RQd7sDwoQhU6bOiq7q2m-SlO
https://drive.google.com/open?id=1Pf3gN5YUOUb62qJ55qOPd-XXrsiH3zzr

Node*  addTwoLists(Node* first, Node* second){
  // Code here
  
  Node *newHead=NULL;
  Node *last=NULL;
  
  Node *temp1=first;
  Node *temp2=second;
  int carry=0,ans=0;
  
  while(temp1!=NULL && temp2!=NULL){
      
      ans=(temp1->data)+(temp2->data)+(carry);
      carry=ans/10;
      ans=ans%10;
      
      // Create a new Node
      
      Node *newNode=new Node;
      newNode->data=ans;
      newNode->next=NULL;
      
      // Add ans to back of the newList
      if(last==NULL){
          
          // List is empty
          
          newHead=newNode;
          last=newNode;
          
      }
      else{
          
          last->next=newNode;
          last=newNode;
          
      }
      temp1=temp1->next;
      temp2=temp2->next;
      
  }
  // If unequal length one of the 2 will not be NULL
  while(temp1!=NULL){
      
      ans=(temp1->data)+carry;
      carry=ans/10;
      ans=ans%10;
      
      Node *newNode=new Node;
      newNode->data=ans;
      newNode->next=NULL;
      last->next=newNode;
      last=newNode;
      
      temp1=temp1->next;
      
  }
  while(temp2!=NULL){
      
      ans=(temp2->data)+carry;
      carry=ans/10;
      ans=ans%10;
      
      Node *newNode=new Node;
      newNode->data=ans;
      newNode->next=NULL;
      last->next=newNode;
      last=newNode;
      
      temp2=temp2->next;
      
  }
  // Last carry
  if(carry!=0){
      Node *newNode=new Node;
      newNode->data=carry;
      newNode->next=NULL;
      last->next=newNode;
      last=newNode;
  }
  return newHead;
  
}
