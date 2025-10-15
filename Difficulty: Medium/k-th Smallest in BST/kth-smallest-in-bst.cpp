/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  vector<int>ans;
  int k;
  void solve(Node * root)
  
  {
      if(!root || ans.size()==k)
      {
          return;
      }
      solve(root->left);
      if(ans.size()==k){
          return;
      }
      ans.push_back(root->data);
       if(ans.size()==k){
          return;
      }
      solve(root->right);
  }
    int kthSmallest(Node *root, int kk) {
        // code here
        k=kk;
        ans.clear();
        solve(root);
        if(ans.size()>=k)
        {
            return ans.back();
            
        }
        return -1;
        
    }
};