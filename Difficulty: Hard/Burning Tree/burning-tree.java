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
    int ans;
    int solve(Node root,int target)
    {
        if(root==null)
        {
            return 0;
        }
        int x=solve(root.left,target);
        int y=solve(root.right,target);
        if(root.data==target)
        {
            ans=Math.max(ans,Math.max(x,y));
            return -1;
        }
        if(x>=0 && y>=0)
        {
            
            return Math.max(x,y)+1;
        }
        else
        {
           ans=Math.max(ans,Math.abs(x)+Math.abs(y));
           return Math.min(x,y)-1;
        }
        
    }
    public int minTime(Node root, int target) {
        // code here
        ans=0;
        solve(root,target);
        return ans;
        
    }
}