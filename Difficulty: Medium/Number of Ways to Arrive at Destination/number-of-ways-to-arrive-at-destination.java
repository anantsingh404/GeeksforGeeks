class Solution {
    class pair
    {
      int node;
      int t;
      pair(int t,int node)
      {
          this.node=node;
          this.t=t;
      }
  }
  @SuppressWarnings("unchecked")
    public int countPaths(int V, int[][] edges) {
        // code here
        
        PriorityQueue<pair>pq=new PriorityQueue<>((a, b) -> a.t - b.t);
        pq.add(new pair(0,0));
        ArrayList<pair> [] adj=new ArrayList[V];
        for(int i=0;i<V;i++)
        {
            adj[i]=new ArrayList<>();
        }
        for(int i=0;i<edges.length;i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            int t=edges[i][2];
            adj[x].add(new pair(t,y));
            adj[y].add(new pair(t,x));
        }
        int []vis=new int[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=Integer.MAX_VALUE;
            
        }
        vis[0]=0;
        int [] com=new int[V];
        for(int i=0;i<V;i++)
        {
            com[i]=0;
        }
        com[0]=1;
        while(pq.size()>0)
        {
            pair x=pq.peek();
            pq.poll();
            int node=x.node;
            int t=x.t;
            for(int i=0;i<adj[node].size();i++)
            {
                int p=adj[node].get(i).t;
                int no=adj[node].get(i).node;
                if(vis[no]>t+p)
                {
                    vis[no]=t+p;
                    pq.add(new pair(t+p,no));
                    com[no]=com[node];
                }
                else if(vis[no]==t+p)
                {
                    com[no]=com[node]+com[no]; 
                }
                
            }
            
            
        }
        return com[V-1];
    }
}
