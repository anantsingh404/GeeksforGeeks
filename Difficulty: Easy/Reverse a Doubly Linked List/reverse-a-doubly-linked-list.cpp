/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
         Node * prev=NULL;
        Node * cur=head;
        Node * next=NULL;
        while(cur)
        {
           next=cur->next;
           cur->next=prev;
           cur->prev=next;
           if(prev)
           {
               prev->prev=cur;
           }
           prev=cur;
           cur=next;
           
           
        }
        return prev;
    }
};