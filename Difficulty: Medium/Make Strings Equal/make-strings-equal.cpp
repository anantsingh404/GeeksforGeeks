class Solution {
  public:
  vector<vector<int>> buildCost(vector<vector<char>> &trans, vector<int> &cost)
{
    int i, j, k;
    const int INF = 1e8;

    vector<vector<int>> arr(26, vector<int>(26, INF));

    for(i = 0; i < 26; i++)
    {
        arr[i][i] = 0;
    }

    for(i = 0; i < trans.size(); i++)
    {
        int x = trans[i][0] - 'a';
        int y = trans[i][1] - 'a';
        int w = cost[i];

        if(arr[x][y] > w)
        {
            arr[x][y] = w;
        }
    }
    for(k = 0; k < 26; k++)
    {
        for(i = 0; i < 26; i++)
        {
            if(arr[i][k] == INF)
            {
                continue;
            }

            for(j = 0; j < 26; j++)
            {
                if(arr[k][j] == INF)
                {
                    continue;
                }

                long long temp = (long long)arr[i][k] + (long long)arr[k][j];
                if(temp < arr[i][j])
                {
                    arr[i][j] = (int)temp;
                }
            }
        }
    }

    return arr;
}
    int minCost(string &s, string &t, vector<vector<char>> &trans,
                vector<int> &cost) {
        // code here
        vector<vector<int>>dp=buildCost(trans,cost);
        if(s.size()!=t.size())
        {
            return -1;
        }
        for(int i=0;i<26;i++)
        {
            dp[i][i]=0;
            
        }
        int costs=0;
        for(int i=0;i<s.size();i++)
        {
          if(s[i]==t[i])
          {
              continue;
          }
         
          else
          {
              int c=1e8;
              int x=s[i]-'a';
              int y=t[i]-'a';
              for(int j=0;j<26;j++)
              {
                 c=min(c,dp[x][j]+dp[y][j]); 
              }
              if(c==1e8){
                  return -1;
              }
              costs+=c;
          }
        }
        
        return costs;
    }
};