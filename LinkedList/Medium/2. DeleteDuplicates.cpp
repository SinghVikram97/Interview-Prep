https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

https://drive.google.com/open?id=10m4QaToMx_6SskJ9Z5FStl7tBYJlyGnb
https://drive.google.com/open?id=13PTZEYZaI6143NQgL1wSsn-cvOahrraO

SORTED -> 11 11 11 21 43 43
Node *removeDuplicates(Node *head)
{
    Node *prev=NULL;
    Node *cur=head;
    while(cur!=NULL){
        
        if(prev==NULL){
            prev=cur;
            cur=cur->next;
        }
        else{
            if(prev->data==cur->data){
                Node *temp=cur;
                prev->next=cur->next;
                cur=cur->next;
                delete temp;
            }
            else{
                prev=cur;
                cur=cur->next;
            }
        }
    }
    return head;
}

UNSORTED 11 21 43 11 21 
https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1/?ref=self
USE A SET TO FIND IF A VALUE SEEN BEFORE

Node *removeDuplicates(Node *head)
{
    Node *prev=NULL;
    Node *cur=head;
    unordered_set<int> s;
    while(cur!=NULL){
        
        if(prev==NULL){
            prev=cur;
            s.insert(cur->data);
            cur=cur->next;
        }
        else{
            if(s.find(cur->data)!=s.end()){
                Node *temp=cur;
                prev->next=cur->next;
                cur=cur->next;
                delete temp;
            }
            else{
                prev=cur;
                s.insert(cur->data);
                cur=cur->next;
            }
        }
    }
    return head;
}
