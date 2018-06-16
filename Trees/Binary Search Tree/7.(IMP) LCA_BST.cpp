The above functions assume that n1 and n2 both are in BST. 
If n1 and n2 are not present, then they may return incorrect result. 
Extend the above solutions to return NULL if n1 or n2 or both not present in BST.

if(search_bst(key1,head)!=NULL && search_bst(key2,head)!=NULL)
	{
		node *temp=find_lca(head,min(key1,key2),max(key1,key2));
		cout<<temp->data<<endl;
	} 
	else
		cout<<"LCA cannot be Found"<<endl;
