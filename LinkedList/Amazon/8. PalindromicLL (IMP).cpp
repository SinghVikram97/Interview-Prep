https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
   
https://drive.google.com/open?id=1aopFhpFhs_GRqcR270cBIWfhLw1MoDJo
https://drive.google.com/open?id=15IQKsLUeKoT79s1geoeE5Jno2qABP8HL
https://drive.google.com/open?id=1q6VMussniKespj5VXI31vS8kjYM9PwyR

/// 1->2->3->3->2->1 becomes 1->2->3->3-<-2-<-1 (Even nodes) (Mid is 2nd 3)
/// 1->2->3->2->1 becomes 1->2->3<-2-<-1 (Even nodes) (Mid is 3)
/// So after reversing start from beg of both list's and check till head1 doesn't become equal to mid

bool isPalindrome(Node *head)
{
    /// 1. find the mid element
    Node *fast=head;
    Node *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    
    // 2. So the mid is slow
    Node *mid=slow;
    
    // 3. Now reverse the linked list starting from mid
    Node *prev=NULL;
    Node *cur=mid;
    Node *next=NULL;
    
    while(cur!=NULL){
        
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    
    // 4. Compare both linked lists starting from both their heads
    Node *head1=head;
    Node *head2=prev; 
    
    // Mid indicates start of 2nd portion so head!=mid
    while(head1!=mid){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

   

