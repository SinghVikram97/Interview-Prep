https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1

https://drive.google.com/open?id=1IBHT9UiLTJbeaBfGLmmGRrrPJzVU4yEf

Time Complexity--> Traversing the tree plus printing array equal to height of the tree at leaf node
O(num_nodes+ num_leafs*height)

void printPathsUtil(Node *root,vector<int> path){
    
    // If null don't print anything
    if(root==NULL){
        return;
    }
    
    // If leaf node print the path that lead to here
    if(root->left==NULL && root->right==NULL){
        
        path.push_back(root->data);
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<"#";
        return;
        
    }
    // Otherwise add cur node data
    path.push_back(root->data);
    // And move to both subtree's for leaf node
    printPathsUtil(root->left,path);
    printPathsUtil(root->right,path);
    
}
void printPaths(Node* root)
{
    vector<int> path;
    printPathsUtil(root,path);
    cout<<endl;
}

........................................................
    IMP
// Here we are passing by reference and safing space
// If we pass by value at each recursive call a new a vector<int> is created and a lot of space wasted
void printPathsUtil(Node *root,vector<int> &path){
    
    // If null don't print anything
    if(root==NULL){
        return;
    }
    
    // If leaf node print the path that lead to here
    if(root->left==NULL && root->right==NULL){
        
        path.push_back(root->data);
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<"#";
        // Backtrack
        path.pop_back();
        return;
        
    }
    // Otherwise add cur node data
    path.push_back(root->data);
    // And move to both subtree's for leaf node
    printPathsUtil(root->left,path);
    printPathsUtil(root->right,path);
    // Backtrack
    path.pop_back();
}
