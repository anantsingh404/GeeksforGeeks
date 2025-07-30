class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& in, int k) {
        // code here
        map<int,int>mp;
        int n=in.size();
        for(int i=0;i<n;i++)
        {
            mp[in[i][0]]++;
            mp[in[i][1]+1]--;
        }
        int maxi=-1;
        int sum=0;
        int flag=0;
        for(auto itr:mp)
        {
            sum+=itr.second;
            if(sum>=k)
            {
                flag=1;
                maxi=max(maxi,itr.first);
            }
            else if(flag)
            {
                maxi=max(maxi,itr.first-1);
                flag=0;
            }
            
        }
        return maxi;
        
    }
};