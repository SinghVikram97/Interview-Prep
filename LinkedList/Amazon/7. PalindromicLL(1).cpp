https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
https://leetcode.com/problems/palindrome-linked-list/

https://drive.google.com/open?id=1NVVj5wDZfdqYc7_L_hwC3MAaXp9TKgtO

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
    if(head==NULL){
        return true;
    }
        
    ListNode *fast=head;
    ListNode *slow=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    // Odd elements
    if(fast->next==NULL){

       ListNode *mid=slow;

       // Start from mid->next for odd elements

       ListNode *start=mid->next;

       // Push elements into stack

       stack<int> s;

       while(start!=NULL){

         s.push(start->val);
         start=start->next;

       }

       // Start from head
       ListNode *temp=head;

       while(!s.empty()){

            if(temp->val!=s.top()){

               return false;

            }
            else{

               temp=temp->next;
               s.pop();
            }

       }

        return true;
    }

    // Even elements
    else if(fast->next->next==NULL){

       // Start from mid

       ListNode *mid=slow->next;

       // Push elements into stack

       stack<int> s;

       ListNode *start=mid;

       while(start!=NULL){

            s.push(start->val);
            start=start->next;

       }

       // Check palindrome start from head

       ListNode *temp=head;

       while(!s.empty()){

            if(temp->val!=s.top()){

               return false;

            }
            else{

              temp=temp->next;
              s.pop();

            }

       }
       return true;

    }
        
        
    }
};
