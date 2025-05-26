/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node * temp=head;
        Node * flag=head;
        while(flag->next!=head)
        {
            flag=flag->next;
        }
        if(flag->data<=data && head->data<=data)
        {
            Node * x=new Node(data);
            flag->next=x;
            x->next=head;
            return head;
        }
        if(temp->data>=data)
        {
            Node * x=new Node(data);
            x->next=temp;
            flag->next=x;
            return x;
        }
        while(temp)
        {
            if(temp->next->data>=data && temp->data<=data)
            {
                 Node * x=new Node(data);
                 Node * y=temp->next;
            temp->next=x;
            x->next=y;
            return head;
            }
            else
            {
            temp=temp->next;
            }
        }
    }
};