class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int ans=1;
        while(i<arr.size())
        {
            mp[arr[i]]++;
            while(j<i-1 && mp.size()>2)
            {   --mp[arr[j]];
               
                if(mp[arr[j]]==0)
                {
                     mp.erase(arr[j]);
              
                }
            j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};