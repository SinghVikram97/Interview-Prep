https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

https://drive.google.com/open?id=13qy5DwoxgKiudGMAx6K9p24VaqtQmjJ_

void intersection(Node **head1, Node **head2,Node **head3)
{
    // Your Code Here
    Node *temp1=*head1;
    Node *temp2=*head2;
    Node *last=*head3;
    
    while(temp1!=NULL && temp2!=NULL){
        
        
        if(temp1->val<temp2->val){
            temp1=temp1->next;
        }
        else if(temp2->val<temp1->val){
            temp2=temp2->next;
        }
        else{
            // Equal
            Node *newNode=new Node;
            newNode->val=temp1->val;
            newNode->next=NULL;
            
            if(last==NULL){
                // Empty list head 3 null intially
                last=newNode;
                *head3=last;
            }
            else{
                last->next=newNode;
                last=newNode;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        
    }
}
