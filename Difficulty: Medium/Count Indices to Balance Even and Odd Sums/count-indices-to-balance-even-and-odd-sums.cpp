class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
       // vector<vector<int>>dp1(n,vector<int>(2,0));
        
        if(n%2)
        {
            dp[n-1][1]=arr[n-1];
            
        }
        else
        {
            dp[n-1][0]=arr[n-1];
        }
       
        for(int i=n-2;i>=0;i--)
        {
            if((i+1)%2==0)
            {
                dp[i][0]=dp[i+1][0]+arr[i];
                dp[i][1]=dp[i+1][1];
            }
            else
            {
                 dp[i][1]=dp[i+1][1]+arr[i];
                dp[i][0]=dp[i+1][0];
            }
        }
         
        int count=0;
        int e=0;
        int o=0;
        for(int i=0;i<n;i++)
        {
            int odd=0;
            int even=0;
            if(i==0 && i<n-1)
            {
              odd=dp[i+1][0];
              even=dp[i+1][1];
            }
            else if(i==0 && i==n-1)
            {
              odd=0;
              even=0;
            }
            
            else if(i>0 && i<n-1)
            {
              odd=dp[i+1][0]+o;
              even=dp[i+1][1]+e;  
            }
            else if(i<n && i>0)
            {
               odd=o;
              even=e;   
            }
            if(odd==even)
            {
                ++count;
            }
            if((i+1)%2==0)
            {
                e+=arr[i];
            }
            else
            {
                o+=arr[i];
            }
          //  cout<<odd<< " "<<even<<endl;
        }
       return count; 
    }
};