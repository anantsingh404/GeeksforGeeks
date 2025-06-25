class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a']++;
        }
        vector<int>ans;
        for(auto itr:mp)
        {
            ans.push_back(itr.second);
        }
        sort(ans.rbegin(),ans.rend());
        int i=0;
        if(ans.size()==1)
        {
            if(ans[0]-k<0)
            {
                return 0;
            }
            return (ans[0]-k)*(ans[0]-k);
        }
        priority_queue<int>pq(ans.begin(),ans.end());
        while(k && pq.size()>0)
        {
            int x=pq.top();
            pq.pop();
            pq.push(x-1);
            k--;
        }
        int res=0;
        while(!pq.empty())
        {
            res+=pq.top()*pq.top();
            pq.pop();
        }
        return res;
        
        
    }
};