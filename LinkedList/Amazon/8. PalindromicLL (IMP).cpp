bool isPalindrome(Node *head)
{
    //Your code here
    
    // Calculate length of linked list
    Node *temp=head;
    int length=0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    
    // Find mid of linked list
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    
   https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
   
   https://drive.google.com/open?id=1aopFhpFhs_GRqcR270cBIWfhLw1MoDJo
   https://drive.google.com/open?id=15IQKsLUeKoT79s1geoeE5Jno2qABP8HL
   https://drive.google.com/open?id=1q6VMussniKespj5VXI31vS8kjYM9PwyR
   
   // Increment mid by one (In even we want 2nd mid element and In odd we don't want mid)
    slow=slow->next;
    
    // Reverse the linked list starting from this slow pointer
    Node *cur=slow;
    Node *prev=NULL;
    Node *next=NULL;
    
    while(cur!=NULL){
        
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        
    }
    
    Node *head1=head;
    Node *head2=prev; //(Cur becomes NULL)
    
    // ex. 1->2->3->3<-2<-1 (Even)
    // ex. 1->2->3->2<-1 (Odd)
    
    // Check if they are equal
    length=length/2;
    
    while(length>0){
        if(head1->data!=head2->data){
            return false;
        }
        else{
            head1=head1->next;
            head2=head2->next;
        }
        length=length-1;
    }
    return true;
    
}
