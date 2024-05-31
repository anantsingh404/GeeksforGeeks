//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

struct TrieNode
{
struct TrieNode *children[26];
bool isLeaf;
TrieNode()
{
    for(int i=0;i < 26;i++)
        {
            children[i]=NULL;
        }
        isLeaf = false;
}
};
TrieNode *t;
void insert(struct TrieNode *root, string key)
{
int first = key[0] - 'a';
if(key.length() == 0)
{
root->isLeaf = true;
return;
}
TrieNode *child ;
if(root->children[first] != nullptr)
{
child = root->children[first];
}
else
{
child = new TrieNode();
root->children[first] = child;
}
insert(child, key.substr(1));
}
bool search(TrieNode *root, string key) 
{
int first = key[0] - 'a';
if(key.length() == 0
&& root->isLeaf)
{
return true;
}
if(root->children[first] && key.length() != 0) return search(root->children[first], key.substr(1));
else return false;
}
 
class Solution{
    public:
 
    bool wordHelper(string &A, int startIndex, vector<int> &dp)
    {
        if(A.length() == startIndex) 
        {
            return true;
        }
        
        if(dp[startIndex] != -1) return dp[startIndex];
        for(int i = startIndex; i < A.length(); i++)
        {
            string currWord = A.substr(startIndex, i - startIndex + 1);
            string newWOrd = currWord;
            if(search(t,currWord) )
            {
 
                if(wordHelper( A, i+1, dp))
                {
                    dp[startIndex] = true;
                    return true;
                }
            }
        }
        dp[startIndex] = false;
        return false;
    }
    int wordBreak(string A, vector<string> &B) 
    {
        t = new TrieNode();
        if(A.length() == 0 ) return 1;
        vector<int> dp(A.length(), -1);
 
        for(auto it : B)
        {
            insert(t, it);
        }
        return wordHelper(A, 0, dp);
    }
    
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends