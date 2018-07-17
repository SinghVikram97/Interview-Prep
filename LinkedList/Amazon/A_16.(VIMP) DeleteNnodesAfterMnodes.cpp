https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

https://drive.google.com/open?id=1bSA3IwNqTIiVRvt4_NVXjZEOF4D76ZKG

void linkdelete(struct node  *head, int M, int N)
{
    if(head==NULL || M==0){
        return NULL;  // Corner case
    }
    node *cur=head;
    node *prev=NULL; // Stores last element of M block
    int mCount=0;
    int nCount=0;
    while(cur!=NULL){
        
        if(mCount<M){
            // Move ahead
            prev=cur;
            cur=cur->next;
            mCount++;
        }
        // We have skipped M nodes prev points to last node in M block
        else{
            if(nCount<N){
                // Delete the cur node
                node *temp=cur;
                prev->next=cur->next;
                cur=prev->next;
                nCount++;
                delete(temp);
            }
            // We can deleted N nodes now is the starting of another M block
            else{
                nCount=0;
                mCount=0;
                // Don't increment cur as it already points to 1st element in M block
            }
        }
    }
}
