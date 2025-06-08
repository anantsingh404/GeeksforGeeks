/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
  bool solve(Node * root,int mini,int maxi)
  {
      if(!root)
      {
          return false;
          
      }
      if(mini>=maxi)
      {
          return true;
      }
      return solve(root->left,mini,root->data-1)||solve(root->right,root->data+1,maxi);
  }
  
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root,1,INT_MAX);
    }
};