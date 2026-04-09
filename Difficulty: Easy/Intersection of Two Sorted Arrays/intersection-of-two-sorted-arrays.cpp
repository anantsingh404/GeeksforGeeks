class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        while(i<n && j<m){
            if(a[i]==b[j])
            {   
                if(!ans.empty() && ans.back()!=a[i])
            {
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(ans.empty())
            {  ans.push_back(a[i]);
                i++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
            }
            else if(a[i]<b[j])
            {
               // ans.push_back(a[i]);
                i++;
               // j++;
            }
            if(a[i]>b[j])
            {
               // ans.push_back(a[i]);
               // i++;
                j++;
            }
        }
        return ans;
    }
};