/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
  void solve(Node *root,int & sum)
  {
      if(!root){
          return;
      }
      solve(root->right,sum);
      int x=root->data;
      root->data=sum;
      sum+=x;
      solve(root->left,sum);
      
     
  }
    void transformTree(Node *root) {
        // code here
        int sum=0;
        solve(root,sum);
    }
};