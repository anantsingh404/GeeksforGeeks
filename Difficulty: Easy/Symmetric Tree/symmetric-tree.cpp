/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
  bool solve(Node *root1,Node * root2)
  {
      if(!root1 && !root2)
      {
          return true;
      }
      if(!root1 || !root2)
      {
          return false;
      }
      bool ans=true;
      if(root1->data!=root2->data)
      {
          ans=false;
      }
      return ans&solve(root1->left,root2->right)&solve(root1->right,root2->left);
  }
    bool isSymmetric(Node* root) {
        // Code here
        return solve(root->left,root->right);
    }
};