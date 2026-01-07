class Solution {
  public:
    int countSubarrays(vector<int>& arr, int kk) {
        // code here
        multiset<int>st;
        multiset<int>st1;
        int ans=0;
        int j=0;
        int k=0;
        for(int i=0;i<arr.size();i++)
        {  
            if(arr[i]%2)
           {
           st.insert(arr[i]);
            st1.insert(arr[i]);
           }
        while(j<i && st.size()>kk)
         {
            if(st.find(arr[j])!=st.end())
            {
                auto itr=st.lower_bound(arr[j]);
                st.erase(itr);
            }
            j++;
         }
         while(k<=i && st1.size()>kk-1)
         {
            if(st1.find(arr[k])!=st1.end())
            {
                auto itr=st1.lower_bound(arr[k]);
                st1.erase(itr);
            }
            k++;
         }
         //cout<<st.size()<<" "<<st1.size()<<" "<<k<<" "<<j<<" "<<i<<endl;
         if(st.size()==kk)
         {
             ans+=k-j;
         }
        }
        return ans;
    }
};