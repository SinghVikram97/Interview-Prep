https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

Computation of lowest common ancestors may be useful, for instance, as part of a procedure for 
determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be 
computed as the distance from the root to n1, plus the distance from the root to n2,
minus twice the distance from the root to their lowest common ancestor

https://drive.google.com/open?id=14pXDbu8D4HCUzDHqJqnCG7fJ_k18hxXq

Time complexity=O(N) n is number of nodes not height of the tree
As if the node is in right subtree we first traverse whole of left subtree to find a path
Then we traverse to right. So effectively we traverse every node once.

Space complexity

Recursion stack in a balanced tree always take space=height of the tree at max
Vector<int> also will take max height of tree space
    
 
bool findPath(Node *root,int data,vector<Node *> &v){
    
    if(root==NULL){
        return false;
    }
    v.push_back(root);
    
    if(root->data==data){
        return true;
    }
    // If we can find a path from this current node to our target node
    // Then this node will be in our vector
    if(findPath(root->left,data,v) || findPath(root->right,data,v)){
        return true;
    }
    // Else if we can't find a path from this node to our target node
    // Remove this node from our vector
    else{
        v.pop_back();
        return false;
    }
}
Node * LCA(Node* root ,int n1 ,int n2 )
{
   vector<Node *> path1;
   vector<Node *> path2;
   
   if(findPath(root,n1,path1) && findPath(root,n2,path2)){
       
       int i=0;
       while(i<path1.size() && i<path2.size()){
           if(path1[i]!=path2[i]){
               break;
           }
           i++;
       }
       return path1[i-1];
   }
   else{
       // Return any value here I am returning -1 as a symbol if a node is not present
       Node *newNode=new Node;
       newNode->data=-1;
       newNode->left=NULL;
       newNode->right=NULL;
       return newNode;
   }
}
