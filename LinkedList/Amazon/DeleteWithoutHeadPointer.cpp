https://drive.google.com/open?id=1Zr2jhPXxqM1j7JTIRM7xaaiHPt7mnSDP

O(1)

void deleteNode(Node *node)
{
   // Your code heret
   
   int swap=node->data;
   node->data=node->next->data;
   node->next->data=swap;
   
   Node *temp=node->next;
   node->next=node->next->next;
   delete temp;
   
}


Doesn't work for last node see in notebook for sentinel node.
