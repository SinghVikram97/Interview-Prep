https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1

https://drive.google.com/open?id=1Sl65XonKPpmkVwCWDmI6HLrmNdAJSvV_

struct node* makeUnion(struct node* head1, struct node* head2)
{
    // code here
    set<int,greater<int> > mySet;  // Store in reverse order so we can add to front (greater<int>)
    node *temp=head1;
    while(temp!=NULL){
        mySet.insert(temp->data);
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL){
        mySet.insert(temp->data);
        temp=temp->next;
    }
    
    // Declare a new list
    node *head3=NULL;
    
    // Iterate over the set
    for(auto it=mySet.begin();it!=mySet.end();it++){
        
        node *newNode=new node;
        newNode->data=(*it);
        
        if(head3==NULL){
            head3=newNode;
            newNode->next=NULL;
        }
        else{
            // Add to front as reverse order in set
            newNode->next=head3;
            head3=newNode;
        }
        
    }
    return head3;
}
