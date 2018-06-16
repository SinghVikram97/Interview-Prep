https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

A tree is heigh balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

https://drive.google.com/open?id=1CK8q7s0P9VplmNloWQlMEIkiqRRTQq4N

pair<int,bool> heightBalanced(Node *root){
    
    if(root==NULL){
        return make_pair(0,true);
    }
    
    pair<int,bool> leftOutput=heightBalanced(root->left);
    pair<int,bool> rightOutput=heightBalanced(root->right);
    int height=1+max(leftOutput.first,rightOutput.first);
    
    // If left subtree and right subtree both are balanced check for current node
    if(leftOutput.second && rightOutput.second){
        
        // If difference of height of subtrees<=1 return true
        if(abs(leftOutput.first-rightOutput.first)<=1){
            return make_pair(height,true);
        }
        // Else return false
        else{
            return make_pair(height,false);
        }
    }
    // Return false
    else{
        return make_pair(height,false);
    }
}

bool isBalanced(Node *root)
{
    pair<int,bool> p=heightBalanced(root);
    if(p.second){
        return true;
    }
    else{
        return false;
    }
}
