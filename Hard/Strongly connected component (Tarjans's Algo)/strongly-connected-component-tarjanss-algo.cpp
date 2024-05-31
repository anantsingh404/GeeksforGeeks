//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
     int discovery=0;
    vector<vector<int>>res;
    void dfs(int u,vector <int> adj[],vector <bool> &visited,stack <int> &st,vector <int> &disc,vector <int>&low,vector<bool> &instack)
    {
        visited[u]=true;
        disc[u]=++discovery;
        low[u]=disc[u];
        st.push(u);
        instack[u]=true;
        for(int v:adj[u])
        {
            if(!visited[v])
            {
                dfs(v,adj,visited,st,disc,low,instack);
                low[u] = min(low[u], low[v]);
            }
            else if(instack[v])
                low[u] = min(low[u], disc[v]);
        }
        if(disc[u]==low[u])
        {
            vector <int> vec;
            while(st.top()!=u)
            {
                vec.push_back(st.top());
                instack[st.top()]=false;
                st.pop();
            }
            vec.push_back(st.top());
            instack[st.top()]=false;
            st.pop();
            sort(vec.begin(),vec.end());
            res.push_back(vec);
        }
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
         vector <int> disc(V,-1);
        vector <int> low(V,-1);
        vector <bool> visited(V,false);
        vector<bool> instack(V,false);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs(i,adj,visited,st,disc,low,instack);
        }
        sort(res.begin(), res.end());
       return res;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends