https://leetcode.com/problems/linked-list-cycle-ii/

https://drive.google.com/open?id=1bfkJtRLkL5bwxneBlt9IHKQ2YVYz5VWf
https://drive.google.com/open?id=1G9hqnzAnJJB_30Vywvm7MrbBUMycADMG
https://drive.google.com/open?id=1gLAwREQOoEP3nkmte-YAzu3TgiV3Kn-a

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        
        if(head==NULL){
            return NULL;
        }
        
        /// 1st detect whether a cycle exists or not
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow){
                
                /// Cycle exists
                ListNode *ptr1=head;
                ListNode *ptr2=slow;
                
                while(ptr1!=ptr2){
                    ptr1=ptr1->next;
                    ptr2=ptr2->next;
                }
                
                return ptr1;
                
            }
            
            
        }
        return NULL;
        
    }
};
