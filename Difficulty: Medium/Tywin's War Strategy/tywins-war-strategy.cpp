class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        vector<int>vp;
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i]%k;
            if(x==0)
            {
                vp.push_back(x);
                continue;
            }
            x=k-x;
            if(x!=k){
            vp.push_back(x);
            }
        }
        sort(vp.begin(),vp.end());
        int count=0;
        for(int i=0;i<arr.size()/2;i++)
        {
            if(vp[i])
            {
                count+=vp[i];
            }
        }
        if(arr.size()%2)
        {
            int x=arr.size()/2;
            ++x;
            count+=vp[x];
        }
        return count;
        
    }
};