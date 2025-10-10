/*
class Node {
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
  vector<int>ans;
    vector<int> zigZagTraversal(Node* root) {
        // code here
        ans.clear();
        queue<Node*>q;
        q.push(root);
        int flag=0;
        while(!q.empty())
        {
          int n=q.size();
          vector<int>temp;
          for(int i=0;i<n;i++)
          {
              Node* x=q.front();
              q.pop();
              temp.push_back(x->data);
              if(x->left)
              {
                  q.push(x->left);
              } if(x->right)
              {
                  q.push(x->right);
              }
          }
          if(flag==1)
          {
              reverse(temp.begin(),temp.end());
              flag=0;
          }else
          {
              flag=1;
          }
          for(int i=0;i<n;i++){
          ans.push_back(temp[i]);
          }
        }
        return ans;
        
    }
};