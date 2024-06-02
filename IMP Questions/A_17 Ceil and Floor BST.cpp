https://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/

https://drive.google.com/open?id=1zRR2tgfyslZqf0RJXmrVVf9c_XzZ_W8U

// Non Recursive
int findCeil(Node* root, int input) {
    Node *ceil=NULL;
    while(root){
        if(root->data==input){
            ceil=root;
            break;
        }else if(root->data<input){
            // move right
            root=root->right;
        }else{
            ceil=root;
            root=root->left;
        }
    }
    if(ceil){
        return ceil->data;
    }else{
        return -1;
    }
}

Similar to upper and lower bound in binary search

Time complexity-O(logn)

int Ceil(Node *root,int key){

    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return root->data;
    }
    /// Root can't be the ceil of key, move right
    if(root->data<key){
        return Ceil(root->right,key);
    }

    /// Now root->data>key so either root->data is ceil
    /// Or if we can find a greater value than key is left subtree
    /// Then that would be the ceil as left subtree as elements less than root->data

    int ceil=Ceil(root->left,key);

    /// If it doesn't return -1 then it means we have an element in left subtree>key
    ceil=(ceil>=key)?(ceil):(root->data);

}

int floor(node *root, int input)
{
    // Base case
    if( root == NULL )
        return -1;
 
    // We found equal key
    if( root->key == input )
        return root->key;
 
    // If root's key is bigger, floor must be in left subtree
    if( root->key> input )
        return floor(root->left, input);
 
    // Else, either right subtree or root has the floor value
    int floor = floor(root->right, key);
    return (floor <= key && floor!=-1) ? floor : root->key;
}
