https://practice.geeksforgeeks.org/problems/absolute-list-sorting/1

https://drive.google.com/open?id=1naCGBZKzzm_FmwGjyfgqb18k9kx22tSZ

void sortList(Node** head)
{
    if(head==NULL || (*head)->next==NULL){
        return;
    }
    // Your Code Here
    Node *cur=*head;
    Node *prev=NULL;
    
    while(cur!=NULL){
        
        // Move it to front
        if(cur->data<0){
            
            // Already in front
            if(prev==NULL){
                prev=cur;
                cur=cur->next;
            }
            else{
                prev->next=cur->next;
                cur->next=*head;
                *head=cur;
                // Prev remains same
                cur=prev->next; // (previous cur->next)
            }
            
        }
        else{
            prev=cur;
            cur=cur->next;
        }
        
    }
    
}
