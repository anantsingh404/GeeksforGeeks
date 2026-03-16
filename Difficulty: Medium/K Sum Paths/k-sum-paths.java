/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    Integer ans;
    void  solve(Node root,HashMap<Integer,Integer>mp,int k,Integer sum)
    {
        if(root==null)
        {
            return;
        }
        sum+=root.data;
        if(sum==k)
        {
          ++ans;  
        }
        if(mp.get(sum-k)!=null)
        {
            ans+=mp.get(sum-k);
        }
        mp.put(sum,mp.getOrDefault(sum,0)+1);
        solve(root.left,mp,k,sum);
        solve(root.right,mp,k,sum);
        mp.put(sum,mp.get(sum)-1);
    }
    public int countAllPaths(Node root, int k) {
        // code here
        ans=0;
        HashMap<Integer,Integer>mp=new HashMap<>();
        solve(root,mp,k,0);
        return ans;
        
    }
}