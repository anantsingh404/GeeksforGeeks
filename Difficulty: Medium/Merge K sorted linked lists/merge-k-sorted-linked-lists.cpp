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
    Node * merge(Node * a,Node * b)
  {
      if(a==NULL)
      {
          return b;
      }
      else if(b==NULL)
      {
          return a;
      }
      else if(a->data<=b->data)
      {
          a->next=merge(a->next,b);
          return a;
      }
      else
      {
          b->next=merge(a,b->next);
          return b;
      }
  }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        Node * res=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            res=merge(res,arr[i]);
        }
        return res;
    
    }
};