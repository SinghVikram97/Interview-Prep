kth element in inorder traversal=kth smallest element in bst

https://www.geeksforgeeks.org/find-median-bst-time-o1-space/

https://drive.google.com/open?id=1RKPb47rGhQ6SN7wpzcrbAfTcVqkqumfN

// Counts the number of nodes in a tree
int countNodes(Node * root) {

    if (root == NULL) {
      return 0;
    } else {
      return 1 + countNodes(root - > left) + countNodes(root - > right);
    }
  }
  // Get kth element in inorder traversal of a bst===kth smallest elmenet in bst
int kthElement(Node * root, int k) {

  // Get no of nodes in left subtree of root
  int leftCount = countNodes(root - > left);

  if (k == leftCount + 1) {
    return root - > data;
  } else if (k > leftCount + 1) {
    return kthElement(root - > right, k - leftCount - 1);
  } else {
    return kthElement(root - > left, k);
  }
}

// Find median
int median(Node * root) {

  int count = countNodes(root);
  if (count == 1) {
    return root - > data;
  }

  if (count % 2 == 1) {
    return kthElement(root, count / 2 + 1) / 2.0;
  } else {
    return (kthElement(root, count / 2) + kthElement(root, count / 2 + 1)) / 2.0;
  }

}
