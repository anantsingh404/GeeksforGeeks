class Solution {
  public:
    long long solve( int i, int j,vector<vector<int>>&arr,int k,int n,int sum,vector<vector<vector<int >>>&dp){
    
    sum+=arr[i][j];
    if(i==n-1&& j==arr[0].size()-1 && sum==k){
        return 1;
    }
    if(sum>k){
        return 0;
    }
    if(dp[i][j][sum]!=-1){
        return dp[i][j][sum];
    }
    long long count=0;
    if(i<n-1){
        count+=solve(i+1,j,arr,k,n,sum,dp);
    }
    if(j<arr[0].size()-1){
        count+=solve(i,j+1,arr,k,n,sum,dp);
    }
    return dp[i][j][sum]=count;
}
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<vector<int >>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
       return solve(0,0,mat,k,n,0,dp);
        
    }
};