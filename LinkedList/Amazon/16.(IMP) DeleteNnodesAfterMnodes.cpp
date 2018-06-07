https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1

https://drive.google.com/open?id=1bSA3IwNqTIiVRvt4_NVXjZEOF4D76ZKG

void linkdelete(struct node  *head, int M, int N)
{
    //Add code here   
    if(head==NULL || N==0){
        return;
    }
    else if(M==0){
        // Delete entire linked list
    }
    
    int mCount=0;
    int nCount=0;
    node *temp=head;
    node *prev; 
    
    while(temp!=NULL){
        
        if(mCount<M){
            prev=temp;  // Last node in current M block
            mCount++;
            temp=temp->next;
        }
        
        else if(mCount==M){
            
            
            if(nCount<N){
                
                prev->next=temp->next; // Not temp 
                nCount++;
                temp=temp->next;
                
                
            }
            else if(nCount==N){
                // Don't increment temp as it already points to 1st element in M block
                nCount=0;
                mCount=0;
            }
            
        }  
    }
}
