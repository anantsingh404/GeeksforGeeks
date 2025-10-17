/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  int count;
  int ans=0;
  void solve(Node * root){
      if(!root){return;}
      ++count;
      solve(root->left);
      solve(root->right);
  }void solve1(Node * root,int &idx)
  {
      if(!root)
      {return;}
      solve1(root->left,idx);
      ++idx;
      if(idx==count)
      {
          ans=root->data;
      }
      
      
      solve1(root->right,idx);
  }
    int findMedian(Node* root) {
        // Code here
        count=0;
        solve(root);
        count=count/2+count%2;
        int idx=0;solve1(root,idx);
        return ans;
        
        
    }
};