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
class d{
    Node node;
    int index;
    d(Node node,int index)
    {
        this.node=node;
        this.index=index;
    }
}
class Solution {
    public ArrayList<ArrayList<Integer>> verticalOrder(Node root) {
        // code here
        TreeMap<Integer,ArrayList<Integer>>mp=new TreeMap<>();
        Queue<d> q=new LinkedList<>();
        ArrayList<ArrayList<Integer>>ls=new ArrayList<>();
        q.add(new d(root,0));
        while(!q.isEmpty())
        {
           d x=q.poll();
           Node temp=x.node;
           int index=x.index;
           if(mp.containsKey(index))
           {
               ArrayList<Integer>t=mp.get(index);
               t.add(temp.data);
               
           }
           else
           {
               ArrayList<Integer> t=new ArrayList<>();
               t.add(temp.data);
               mp.put(index,t);
           }
           if(temp.left!=null)
           {
               q.add(new d(temp.left,index-1));
           }
           if(temp.right!=null)
           {
               q.add(new d(temp.right,index+1));
           }
        }
        for(ArrayList<Integer>list:mp.values())
        {
            ls.add(list);
        }
        return ls;
    }
}
