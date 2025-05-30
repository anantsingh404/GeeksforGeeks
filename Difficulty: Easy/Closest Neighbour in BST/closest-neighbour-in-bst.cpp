/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  int ans=INT_MAX;
  void solve(Node * root,int n)
  {
        if(!root)
  {
      return;
  }
      if(root->data<=n)
      {
          ans=root->data;
      }
      if(root->data<n)
      {
          solve(root->right,n);
      }
      if(root->data>n)
      {
        solve(root->left,n);  
      }
  }
  
    int findMaxFork(Node* root, int k) {
        // code here
        solve(root,k);
          if(ans!=INT_MAX)
        {
            return ans;
        }
        return -1;
        return ans;
        
    }
};