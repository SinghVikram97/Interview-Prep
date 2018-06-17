https://practice.geeksforgeeks.org/problems/check-for-bst/1

https://drive.google.com/open?id=1bHoYGQN5P2Mx-vYrtZuJ6kct08I4CBq-
https://drive.google.com/open?id=1NiTvSSk-Q6mbDjh_9vBP7TqfYc3F--Hn
https://drive.google.com/open?id=1o985xJclOT-u-lIVtq3ugIylZ8nZGSzz
https://drive.google.com/open?id=1devIzBsaANZYHK7Objd65p2WyZcZZn4S

// 1st is isBST 2nd mininum and 3rd is maximum of that subtree
pair<bool,pair<int,int> > BST(Node *root){
    
    if(root==NULL){
        return make_pair(true,make_pair(INT_MAX,INT_MIN));
    }
    
    pair<bool,pair<int,int> > leftOutput=BST(root->left);
    pair<bool,pair<int,int> > rightOutput=BST(root->right);
    
    int minimum,maximum;
    
    minimum=min(root->data,min(leftOutput.second.first,rightOutput.second.first));
    maximum=max(root->data,max(leftOutput.second.second,rightOutput.second.second));
    
    if(leftOutput.first && rightOutput.first){
            
            if(root->data>leftOutput.second.second && root->data<rightOutput.second.first){
                return make_pair(true,make_pair(minimum,maximum));
            }
            else{
                return make_pair(false,make_pair(minimum,maximum));
            }
            
    }
    else{
        return make_pair(false,make_pair(minimum,maximum));
    }
}   
bool isBST(Node* root) {
    pair<bool,pair<int,int> > p=BST(root);
    
    if(p.first){
        return true;
    }
    else{
        return false;
    }
}
