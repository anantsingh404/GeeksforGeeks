//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int r[8]={2,2,-2,-2,1,1,-1,-1};
        int c[8]={1,-1,-1,1,2,-2,2,-2};
	int minStepToReachTarget(vector<int>&kp, vector<int>&tp, int n){
	    // Code here
	    int count=0;
	    queue<pair<int,int>>q;
	    q.push({kp[0]-1,kp[1]-1});
	     vector<vector<int>> vis(n,vector<int> (n,0));
	     vis[kp[0]-1][kp[1]-1]++;
	   
	    while(!q.empty())
	    {  
	        int z=q.size();
	        for(int l=0;l<z;l++){
	        pair<int,int>p=q.front();
	        int i=p.first;
	        int j=p.second;
	        if(tp[0]==i+1 && tp[1]==j+1)
	        {
	            return count;
	        }
	        q.pop();
	        for(int k=0;k<8;k++)
	        {
	            int x=i+r[k];
	            int y=j+c[k];
	            if(x>=0 && x<n && y>=0 && y<n && !vis[x][y])
	            {
	               q.push({x,y});
	               vis[x][y]++;
	               
	            }
	            
	        }
	    }
	    ++count;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends