class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        bool ans=true;
        int fc=0;
        int tc=0;int ttc=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==5)
            {
                ++fc;
            }
            else if(arr[i]==10)
            {
                if(fc>0)
                {
                    --fc;
                    ++tc;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(fc>0 && tc>0)
                {
                    fc-=1;
                    tc-=1;
                    ttc+=1;
                }
                else if(fc>=3)
                {
                    fc-=3;
                    ttc+=1;
                }
                else
                {
                    return false;
                }
            }
        }
        return ans;
    }
};