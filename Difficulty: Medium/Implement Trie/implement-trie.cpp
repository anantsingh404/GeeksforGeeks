//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class TrieNode {
public:
    TrieNode* child[26];
    bool istrue;
    TrieNode() {
        istrue = false;
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
    }
};

class Trie {
  public:
     TrieNode * root;
     
    Trie() {
        // implement Trie
       root=new TrieNode();
    }

    void insert(string &s) {
        // insert word into Trie
         TrieNode * flag=root;
        int n=s.size();
        for(int i=0;i<n;i++ )
        {
            int x=s[i]-'a';
            if(flag->child[x]!=NULL)
            {
               flag=flag->child[x]; 
            }
            else
            {
                flag->child[x]=new TrieNode();
                flag=flag->child[x];
            }
        }
        flag->istrue=true;
    }

    bool search(string &s) {
        // search word in the Trie
     TrieNode * flag=root;
        int n=s.size();
        for(int i=0;i<n;i++ )
        {
            int x=s[i]-'a';
            if(flag->child[x]!=NULL)
            {
               flag=flag->child[x]; 
            }
            else
            {
                return false;
            }
        }
        if(flag->istrue)
        {
            return true;
        }
        return false;
    }

    bool isPrefix(string &s) {
        // search prefix word in the Trie
    
        int n=s.size();
         TrieNode * flag=root;
        for(int i=0;i<n;i++ )
        {
            int x=s[i]-'a';
            if(flag->child[x]!=NULL)
            {
               flag=flag->child[x]; 
            }
            else
            {
                return false;
            }
        }
        return true;
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends