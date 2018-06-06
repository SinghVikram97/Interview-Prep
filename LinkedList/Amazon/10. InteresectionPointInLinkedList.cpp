https://leetcode.com/problems/intersection-of-two-linked-lists/description/

https://drive.google.com/open?id=11ngf2M0VpKDJ3aIUMpMBTzShQukJem3L

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int length1=0,length2=0;
        
        ListNode *temp1=headA;
        ListNode *temp2=headB;
        
        while(temp1!=NULL){
            length1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            length2++;
            temp2=temp2->next;
        }
        int diff;
        if(length1<=length2){
            // B linked list is bigger
            diff=length2-length1;
            // Move headB by diff
            while(diff--){
                headB=headB->next;
            }
        }
        else{
            // A linked list is bigger
            diff=length1-length2;
            // Move headA by diff
            while(diff--){
                headA=headA->next;
            }
        }
        while(headA!=NULL && headB!=NULL){
            if(headA==headB){
                return headA;
            }
            else{
                headA=headA->next;
                headB=headB->next;
            }
        }
        return NULL;
    }
};
