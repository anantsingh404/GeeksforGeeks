/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  map<pair<Node *,int>,int>mp;
  int solve(Node * root,int take)
  {
      if(!root)
      {
          return 0;
      }
      if(mp.find({root,take})!=mp.end())
      {
          return mp[{root,take}];
          
      }
      int ans=0;
      if(take==1)
      {
          ans=root->data+solve(root->left,0)+solve(root->right,0);
          ans=max(ans,solve(root->left,1)+solve(root->right,1));
      }
      else
      {
           ans=max(ans,solve(root->left,1)+solve(root->right,1));
      }
      return mp[{root,take}]=ans;
  }
    int getMaxSum(Node *root) {
        // code here
        mp.clear();
        return solve(root,1);
        
    }
};