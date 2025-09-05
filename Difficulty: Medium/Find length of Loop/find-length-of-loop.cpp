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
    int lengthOfLoop(Node *head) {
       Node * fast=head;
        Node * slow=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            if(fast->next)
            {
                fast=fast->next->next;
            }
            if(slow==NULL || fast==NULL)
            {
                return 0;
            }
            if(slow==fast)
            {  
                slow=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                int count=1;
                Node * temp=slow;
                temp=temp->next;
                while(temp!=slow)
                {
                    temp=temp->next;
                    ++count;
                }
                return count;
            }
        }
            return 0;
    }
};