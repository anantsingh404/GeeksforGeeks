class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        queue<string>q;
        vector<string>ans;
        q.push("1");
        while(!q.empty())
        {
            string x=q.front();
            q.pop();
            ans.push_back(x);
            q.push(x+"0");
            q.push(x+"1");
            if(ans.size()==n)
            {
                break;
            }
        }
        return ans;
    }
};