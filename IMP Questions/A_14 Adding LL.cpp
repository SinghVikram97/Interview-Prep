https://leetcode.com/problems/add-two-numbers-ii/description/

https://drive.google.com/open?id=1aX7mDj-CRYQkne8n3qExM7DZHqHycBb-
https://drive.google.com/open?id=16jkL66pYcTpWW9VUJGAf9-mR_sOQlog9

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        stack<int> s1;  // Add elements of 1st list to s1
        stack<int> s2;  // Second list to s2
        
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        
        while(temp1!=NULL){
            s1.push(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            s2.push(temp2->val);
            temp2=temp2->next;
        }
        
        ListNode *head=NULL;
        int sum=0,carry=0,top1,top2;
        
        // While one of them not empty
        while(!s1.empty() || !s2.empty()){
            
            top1=0;
            top2=0;

            // If empty then top1 remains 0 ie. it's contribution is 0
            if(!s1.empty()){
                top1=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                top2=s2.top();
                s2.pop();
            }

            sum=(top1+top2+carry);
            
            carry=sum/10;
            sum=sum%10;
            
            // Create a new node with sum as data
            ListNode *newNode=new ListNode(sum);
                                           
            // Add sum to front of the list since we want MSD at front
            newNode->next=head;
            head=newNode;
        }
        

        
        // Last carry ex both list of same size 5->NULL and 5->NUll then carry will be 1
        if(carry!=0){
            ListNode *newNode=new ListNode(carry);
            newNode->next=head;
            head=newNode; 
        }
        return head;
    }
};
