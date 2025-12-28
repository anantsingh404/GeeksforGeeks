class Solution {
  public:
    int minTime(vector<int>& r, int n) {
        // code here
         int ans = INT_MAX;
    int mini = 0;
    int maxi = 1e9;

    while (mini <= maxi)
    {
        int mid = (mini + maxi) / 2;
        int count = 0;

        for (int i = 0; i < r.size(); i++)
        {
            int p = (int)(-r[i] + sqrt(r[i]*r[i]+8.0*r[i]* mid)) / (r[i]*2);
            int x = max(0, p);
            count += x;
        }

        if (count >= n)
        {
            ans = mid;
            maxi = mid - 1;
        }
        else
        {
            mini = mid + 1;
        }
    }

    return ans;
        
    }
};