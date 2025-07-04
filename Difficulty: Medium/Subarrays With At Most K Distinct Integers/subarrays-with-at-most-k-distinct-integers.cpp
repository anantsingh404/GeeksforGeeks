class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int i=0;
        int j=0;
        int sum=0;
        unordered_map<int,int>mp;
        while(i<n)
        {
          
          mp[arr[i]]++;
          while(j<i && mp.size()>k)
          {
              --mp[arr[j]];
              if(mp[arr[j]]==0)
              {
                  mp.erase(arr[j]);
              }
              j++;
              
          }
          sum+=j;
          i++;
          
        }
        long long ans=1ll*n*(n+1)/2;
        return ans-sum;
    }
};