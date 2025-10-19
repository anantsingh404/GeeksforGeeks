/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    
    void inorder(Node* root, int target,
                 priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 greater<pair<int, int>>>& pq)
    {
        if (!root)
            return;

        
        inorder(root->left, target, pq);

        
        pq.push({abs(root->data - target), root->data});

        
        inorder(root->right, target, pq);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        
        inorder(root, target, pq);

        
        vector<int> result;
        while (!pq.empty() && k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};