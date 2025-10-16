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
  Node* solve(Node* root, int l, int r) {
    if (!root) {
        return NULL;
    }

    // If current node's value is less than l, then discard left subtree
    // and move to right
    if (root->data < l) {
        return solve(root->right, l, r);
    }

    // If current node's value is greater than r, discard right subtree
    // and move to left
    if (root->data > r) {
        return solve(root->left, l, r);
    }

    // If current node's value is within [l, r],
    // fix its left and right subtrees recursively
    root->left = solve(root->left, l, r);
    root->right = solve(root->right, l, r);

    return root;
}

    Node* removekeys(Node* root, int l, int r) {
        // code here
        return solve(root,l,r);
    }
};