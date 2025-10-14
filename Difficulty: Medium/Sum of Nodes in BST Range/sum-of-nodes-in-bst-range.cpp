/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  int solve(Node * root,int l,int r)
  {
      if(!root)
      {
      return 0;
      }
      int ans=0;
      if(root->left && root->data>l)
      {
       ans+=solve(root->left,l,r);   
      }
      if(root->right && root->data<r)
      {
       ans+=solve(root->right,l,r);   
      }
      if(root->data>=l && root->data<=r)
      {
          ans+=root->data;
      }
      return ans;
  }
    int nodeSum(Node* root, int l, int r) {
        // code here
        return solve(root,l,r);
    }
};
