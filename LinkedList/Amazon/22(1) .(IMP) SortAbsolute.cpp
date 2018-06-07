https://practice.geeksforgeeks.org/problems/absolute-list-sorting/1

https://drive.google.com/open?id=18r9a-6LGp_l0CxvyjwbEJY3OrbWm5uMD

void sortList(Node** head)
{
    // Your Code Here
    if(*head==NULL || (*head)->next==NULL){
        return;
    }
    
    Node *pp=NULL;  // Previous positive
    Node *pn=NULL;  // Previous negative
    Node *ph=NULL;  // Positive head
    Node *nh=NULL;  // Negative head
    Node *cur=*head;
    while(cur!=NULL){
        
        if(cur->data<0){
            
            if(pn==NULL){
                nh=cur;
                pn=cur;
                cur=cur->next;
            }
            else{
                pn->next=cur;
                pn=cur;
                cur=cur->next;
            }
            
        }
        else{
            if(pp==NULL){
                ph=cur;
                pp=cur;
                cur=cur->next;
            }
            else{
                pp->next=cur;
                pp=cur;
                cur=cur->next;
            }
        }
        
    }
    // In case of all +ve or all -ve pn or pp will be null
    if(pn!=NULL){
        pn->next=NULL;  // Imp see the photo
    }
    if(pp!=NULL){
        pp->next=NULL;   // Imp see the photo
    }
    
    // Node *temp1=ph;
    // Node *temp2=nh;
    // while(temp1!=NULL){
    //     cout<<temp1->data<<"-->";
    //     temp1=temp1->next;
    // }
    // cout<<endl;
    // while(temp2!=NULL){
    //     cout<<temp2->data<<">";
    //     temp2=temp2->next;
    // }
    // cout<<endl;
    
    // 2 list with positive head and negative head reverse negative list
    
    Node *prev=NULL;
    cur=nh;
    Node *next=NULL;
    
    while(cur!=NULL){
        
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    
    // prev is the newhead
    // add positive list to tail of negative list (tail is equal to head before reversing)
    
    // nh can be NULL if all positive
    if(nh!=NULL){
    nh->next=ph;
    *head=prev;
    }
    // All positive ie nh==NULL
    else{
        *head=ph;
    }
   
    
}
