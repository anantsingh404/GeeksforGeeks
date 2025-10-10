/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int ans;
  int solve(Node * root)
  {
      if(!root)
      {
          return 0;
      }
      int x=solve(root->left);
      int y=solve(root->right);
      ans=max(ans,root->data);
      ans=max(ans,x+y+root->data);
       ans=max(ans,x+root->data);
        ans=max(ans,y+root->data);
      return max(max(x,y)+root->data,root->data);
  }
    int findMaxSum(Node *root) {
        // code here
        ans=INT_MIN;
        solve(root);
        return ans;
    }
};