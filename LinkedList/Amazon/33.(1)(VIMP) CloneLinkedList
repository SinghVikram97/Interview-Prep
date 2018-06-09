https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

https://drive.google.com/open?id=1Kb8xA6eV1_AkLC8SD7DpbkFepPfOyd8H

Node * copyList(Node *head)
{
     // Your code here
     // 1. Copy only the next pointer and data and let arb pointer be NULL
     Node *cloneHead=NULL;
     Node *prev=NULL;
     Node *temp=head;
     
     while(temp!=NULL){
         
         Node *newNode=new Node;
         newNode->data=temp->data;
         newNode->next=NULL;   // Inserting at back
         
         if(prev==NULL){
             // 1st element
             cloneHead=newNode;
             prev=newNode;
         }
         else{
             prev->next=newNode;
             prev=newNode;
         }
         temp=temp->next;
     }
     
     // 2. Store a one to one mapping from original list to cloned list in a map
     map<Node *,Node *> myMap;
     Node *originalTemp=head;
     Node *clonedTemp=cloneHead;
     
     while(originalTemp!=NULL){
         
         myMap[originalTemp]=clonedTemp;
         originalTemp=originalTemp->next;
         clonedTemp=clonedTemp->next;
         
     }
     
     // 3. Now traverse the 1st list and 2nd list to assign arb pointer
     originalTemp=head;
     clonedTemp=cloneHead;
     while(originalTemp!=NULL){
         
         clonedTemp->arb=myMap[originalTemp->arb];
         originalTemp=originalTemp->next;
         clonedTemp=clonedTemp->next;
     }
    return cloneHead;
}
