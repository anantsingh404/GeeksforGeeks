class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        vector<int>mp(1e3+1,0);
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(int i=1;i<=1e3;i++)
        {
           for(int j=1;j<=1e3;j++)
           {
               if(mp[i]>0 && mp[j]>0)
               {
                   if(i==j)
                   {
                       if(mp[i]>=2)
                       {
                           int x=i*i+j*j;
                           int y=sqrt(x);
                           if(mp[y]>0 && y*y==x)
                           {
                               return true;
                           }
                       }
                   }
                   else
                   {
                           int x=i*i+j*j;
                           int y=sqrt(x);
                           if(mp[y]>0 && y*y==x)
                           {
                               return true;
                           } 
                   }
               }
           }
        }
        return false;
        
        
    }
};