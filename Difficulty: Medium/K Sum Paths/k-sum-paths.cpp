//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
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
  int solve(Node *root,int k,int sum)
  {   
      if(!root)
      {
          return 0;
      }
      int ans=0;
      if(sum==k)
      {
        ++ans;  
      }
      int p=0,q=0;
      if(root->left){
      p=solve(root->left,k,sum+root->left->data);
      }
      if(root->right){
      q=solve(root->right,k,sum+root->right->data);
      }
      return p+q+ans;
      
      
  }
    int sumK(Node *root, int k) {
        if(!root)
        {
            return 0;
        }
        int x=solve(root,k,root->data);
        int p=sumK(root->left,k);
        int q=sumK(root->right,k);
        return x+p+q;
        
    }
};

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends