https://leetcode.com/problems/swap-nodes-in-pairs/description/



RECURSIVE SOLUTION--> USES SPACE DUE TO RECURSION https://drive.google.com/open?id=1l74yTuBOnIajBSd1wBCQN6EuU6ORXEPf

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* rightPart=swapPairs(head->next->next);

        ListNode* newHead=head->next;

        newHead->next=head;
        head->next=rightPart;

        return newHead;
    }
};

WITHOUT RECURSION https://drive.google.com/open?id=1VW9zHftnpBcB1ZsmCyuLv9mcacwWTuCU

ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode *prev=NULL,*cur=head,*next,*newHead;
        
        while(cur!=NULL && cur->next!=NULL){
            next=cur->next->next;
            cur->next->next=cur;
            if(prev!=NULL){
                prev->next=cur->next;
            }
            else{
                newHead=cur->next;
            }
            cur->next=NULL;
            prev=cur;
            cur=next;
        }
        // Odd elements last would be left out
        if(cur!=NULL){
            prev->next=cur;
        }
        return newHead;
    }

