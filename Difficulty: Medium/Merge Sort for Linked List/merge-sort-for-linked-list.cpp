/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
   Node * merge(Node * head1,Node * head2)
  {
      if(!head1)
      {
          return head2;
      }
      if(!head2)
      {
          return head1;
      }
      
      if(head1->data>head2->data)
      {   
          head2->next=merge(head1,head2->next);
         return head2;
      }
      else
      {   
          head1->next=merge(head1->next,head2);
      }
      return head1;
  }
    Node* mergeSort(Node* head) {
        // code here
        if(!head || !head->next)
        {
            return head;
        }
        Node * slow=head;
        Node * fast=head;
        Node * prev=NULL;
        while(fast && fast->next)
        {  
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        head=mergeSort(head);
        slow=mergeSort(slow);
        head=merge(head,slow);
        return head;
        
    }
};