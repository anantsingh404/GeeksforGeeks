/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        int count=0;
        Node * temp=head;
            Node* first=NULL;
        while(temp)
        {
            
            if(count==k-1)
            {
                first=temp;
            }
            ++count;
            temp=temp->next;
        }
        if(count<k)
        {
            return head;
        }
        Node * sec=NULL;
        temp=head;
        while(temp)
        {
            if(count==k)
            {
                sec=temp;
                break;
            }
            temp=temp->next;
            --count;
        }
        swap(first->data,sec->data);
        return head;
    }
};