https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

// If we want 3rd list in sorted order
https://drive.google.com/open?id=1stNiXhxMdHPFrpKKvfyHDlplucFMie6J

struct node* findIntersection(struct node* head1, struct node* head2)
{
    // code here
    node *temp=head1;
    // 1. Traverse the 1st list and keep a count of numbers in a map
    map<int,int> myMap;
    
    while(temp!=NULL){
        myMap[temp->data]++;
        temp=temp->next;
    }
    // 2. Create the new head
    node *head3=NULL;
    // 3. Traverse the 2nd list and find interesection
    temp=head2;
    while(temp!=NULL){
        
        if(myMap[temp->data]!=0){
            // Insert into new list
            
            node *newNode=new node;
            newNode->data=temp->data;
            
            if(head3==NULL){
                head3=newNode;
                newNode->next=NULL;
            }
            else{
                // Insert at front
                newNode->next=head3;
                head3=newNode;
            }
            myMap[temp->data]--;
        }
        temp=temp->next;
    }
    return head3; // If no interesection it returns NULL as head3 intially NULL
}
