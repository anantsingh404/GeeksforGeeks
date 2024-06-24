//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


class trie{
    public:
    trie * link[2];
    trie()
    {
        link[0]=NULL;
        link[1]=NULL;
    }
};
class Solution{   
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
    int findmax(int num)
    {
        int maxi=0;
        trie * node=root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num >> i) & 1;
        if (node -> link[!bit]) {
          maxi = maxi | (1 << i);
          node = node -> link[!bit];
        } else {
          node = node -> link[bit];
        }
      }
      return maxi;
        
    }
    int maxSubarrayXOR(int n, int arr[]){    
        //code here
        root=new trie();
        int ans=0;
        insert(0);
        ans=findmax(arr[0]);
        insert(arr[0]);
        for(int i=1;i<n;i++)
        {   arr[i]=arr[i]^arr[i-1];
            ans=max(ans,findmax(arr[i]));
            insert(arr[i]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends