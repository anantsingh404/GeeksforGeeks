//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
                int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cost(n,vector<int>(m,1e9));
        cost[0][0] = grid[0][0];
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({cost[0][0],{0,0}});
        
        int row[] = {0,-1,0,1};
        int col[] = {1,0,-1,0};
        
        while(!pq.empty()){
            int cst = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            for(int k=0;k<4;k++){
                int nr = i+row[k];
                int nc = j+col[k];
                
                if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                
                if(cost[nr][nc] > cst+grid[nr][nc]){
                    cost[nr][nc] = cst+grid[nr][nc];
                    pq.push({cost[nr][nc],{nr,nc}});
                }
            }
        }
        return cost[n-1][m-1];

    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends