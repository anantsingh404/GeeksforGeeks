/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
          if(head1==NULL || head2==NULL) return 0;
   Node* curr1=head1;
   Node* curr2=head2;
   while(curr1!=curr2){
       if(curr1==NULL) curr1=head2;
       else curr1=curr1->next;
       if(curr2==NULL)curr2=head1;
       else curr2=curr2->next;
   }
   return curr1;
    }
};