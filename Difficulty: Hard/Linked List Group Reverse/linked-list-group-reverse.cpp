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
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(!head)
        {
            return NULL;
        }
        Node *cur=head;
        Node * prev=NULL;
        int count=0;
        while(cur && count<k)
        {
          if(prev)
          {
                Node * next=cur->next;
                
                cur->next=prev;
                prev=cur;
                cur=next;
                
          }
          else
          {
              Node * next=cur->next;
              cur->next=NULL;
              prev=cur;
              cur=next;
              
          }
          ++count;
        }
        head->next=reverseKGroup(cur,k);
        return prev;
        
    }
};