//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
 class trie{
    public:
    trie * link[2];
    trie()
    {
        link[0]=NULL;
        link[1]=NULL;
    }
};
class Solution
{
    public:
    trie * root;
    void insert(int num)
    {
        trie * cur=root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num >> i) & 1;
            if(cur->link[bit]==NULL)
            {
                cur->link[bit]=new trie();
                
            }
            cur=cur->link[bit];
            
        }
    }
    int findMax(int num) {
      trie * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> link[!bit]) {
          maxNum = maxNum | (1 << i);
          node = node -> link[!bit];
        } else {
          node = node -> link[bit];
        }
      }
      return maxNum;
    }
      int maxXor(vector<int> &arr) {
        int n=arr.size();
        root=new trie();
        for(int i=0;i<n;i++)
        {
            insert(arr[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,findMax(arr[i]));
        }
        return maxi;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends