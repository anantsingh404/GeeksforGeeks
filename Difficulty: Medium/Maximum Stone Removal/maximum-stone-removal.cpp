class ds{
    public:
    vector<int>par,size;
    ds(int n)
    {
      par.resize(n);
      for(int i=0;i<n;i++)
      {
          par[i]=i;
      }
      size.resize(n,1);
    }
    int fp(int x)
    {
        if(par[x]==x)
        {
            return x;
        }
        return par[x]=fp(par[x]);
    }
    void join(int x,int y)
    {
        int p=fp(x);
        int q=fp(y);
        if(p==q)
        {
            return;
            
        }
        if(size[p]<size[q]){
            par[p]=q;
            size[q]+=size[p];
        }
        else
        {
            par[q]=p;
            size[p]+=size[q];
        }
    }
    
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        
    int n=0;
    int m=0;
    for(int i=0;i<stones.size();i++)
    {
        n=max(stones[i][0]+1,n);
        m=max(stones[i][1]+1,m);
    }
    ds x(n+m);
    int ans=0;
    for(auto itr:stones)
    {
        int p=itr[0];
        int q=itr[1];
        x.join(p,n+q);
    }
    for(int i=0;i<n+m;i++)
    {
      int p=i;
      
      int xx=x.fp(p);
      if(xx==p && x.size[p]>1)
      {
          ++ans;
      }
      
    }
    return stones.size()-ans;
    
    }
};