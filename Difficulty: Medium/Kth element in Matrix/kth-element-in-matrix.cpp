class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n=mat.size();
        priority_queue<int>max;
  
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          max.push(mat[i][j]);
          if(max.size()>k)
          {
              max.pop();
          }
      }
  }return max.top();
    }
};