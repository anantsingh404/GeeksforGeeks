//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isValid(int x, int y, int X, int Y) 

    {

        return (x>=0) && (y>=0) && (x<X) && (y<Y); 

    }

  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        queue<pair<int,int>>q;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int nextx,nexty;
        
        if(A[0][0]==0)
        {
            return -1;
        }
        q.push({0,0});
        dist[0][0]=0;
        while(!q.empty())
        {
            auto current=q.front();
            q.pop();
            int curx=current.first;
            int cury=current.second;
            if(curx==X && cury==Y)
            {
                return dist[curx][cury];
            }
            for(int i=0;i<4;i++)
            {
                nextx=curx+dx[i];
                nexty=cury+dy[i];
                if(isValid(nextx,nexty,N,M) && dist[nextx][nexty]==INT_MAX && A[nextx][nexty]==1)
                {
                    q.push({nextx,nexty});
                    dist[nextx][nexty]=dist[curx][cury]+1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends