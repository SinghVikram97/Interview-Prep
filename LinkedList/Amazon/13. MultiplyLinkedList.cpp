https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1

https://drive.google.com/open?id=14cOO01qLcSOh6vt_P_kOxIPGIYSyq_7J

long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long int m=1000000007;
  
  long long int num1=0,num2=0;
  Node *temp1=l1;
  Node *temp2=l2;
  
  while(temp1!=NULL){
      num1=((((num1%m)*10)%m)+((temp1->data)%m))%m;
      temp1=temp1->next;
  }
  while(temp2!=NULL){
      num2=((((num2%m)*10)%m)+((temp2->data)%m))%m;
      temp2=temp2->next;
  }
  return ((num1%m)*(num2%m))%m;
}
