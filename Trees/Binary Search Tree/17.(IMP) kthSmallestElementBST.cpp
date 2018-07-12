https://leetcode.com/problems/kth-smallest-element-in-a-bst/
    
https://drive.google.com/open?id=19qJCUe8lW7U9n6245uqEccjFJa-9__6p
   
................................................................. 
O(N) TIME O(N) SPACE    

void kthSmallestHelper(TreeNode *root,vector<int> &v){

        if(root==NULL){
            return;
        }        
        kthSmallestHelper(root->left,v);
        v.push_back(root->val);
        kthSmallestHelper(root->right,v);
        
}
int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        kthSmallestHelper(root,v);
        return v[k-1];
}

..............................................................

TIME-> O(N) SPACE-> O(1) IF RECURSION SPACE INGNORED

void kthSmallestHelper(TreeNode * root, int & ans, int & k) {

  if (root == NULL) {
    return;
  }
  kthSmallestHelper(root - > left, ans, k);
  // Visited a node decrease k
  k--;
  if (k == 0) {
    ans = root - > val;
    return;
  }
  kthSmallestHelper(root - > right, ans, k);
  
}

int kthSmallest(TreeNode * root, int k) {
  int ans;
  kthSmallestHelper(root, ans, k);
  return ans;
}

...............................................................

AUGMENTED TREE WHICH STORE COUNT OF NODES IN LEFT SUBTREE

https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

https://drive.google.com/open?id=1ChmFjN6yRxwqBLG6LaOCIV3EUfUPXxdQ
https://drive.google.com/open?id=1Fn7jHdnDSbbXTTRs6wtdRF6yvf0pvTnH

struct Node {
  int data;
  int lCount;

  Node * left;
  Node * right;
};
int KthSmallestElement(Node * root, int k) {
  if (k == root - > lCount + 1) {
    return root - > data;
  } else if (k > root - > lCount + 1) {
    return KthSmallestElement(root - > right, k - root - > lCount - 1);
  } else {
    return KthSmallestElement(root - > left, k);
  }
}
