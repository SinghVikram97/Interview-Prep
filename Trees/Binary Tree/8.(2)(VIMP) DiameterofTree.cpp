Can also be asked as distance between 2 farthest nodes

https://drive.google.com/open?id=10AEfLso0FhxAOTD6e4FrInlq3yJje9ny
https://drive.google.com/open?id=1vt63mxK-6TeciHmHU5VTZIDVUWmnK0j2

Coding Ninjas Video

pair<int,int> heightDiameter(Node *root){
    
    if(root==NULL){
        return make_pair(0,0);
    }
    
    pair<int,int> leftOutput=heightDiameter(root->left);
    pair<int,int> rightOutput=heightDiameter(root->right);
    
    // We need to return height and diameter
    // Height=1+max(lh,rh)
    int height=1+max(leftOutput.first,rightOutput.first);
    int diameter;

    int op1=1+leftOutput.first+rightOutput.first;
    int op2=leftOutput.second;
    int op3=rightOutput.second;
    
    diameter=max(op1,max(op2,op3));
    
    return make_pair(height,diameter);
    
}
int diameter(Node* root)
{
   
   if(root==NULL){
       return 0;
   }
   
   pair<int,int> ans=heightDiameter(root);
   
   return ans.second;
}
