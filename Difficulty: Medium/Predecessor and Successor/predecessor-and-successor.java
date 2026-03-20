class Solution {

    void findpre(Node root, int x, Node[] pre) {
        if (root == null) {
            return;
        }

        if (root.data >= x) {
            findpre(root.left, x, pre);
        }

        if (root.data < x) {
            pre[0] = root;
            findpre(root.right, x, pre);
        }
    }

    void findsuc(Node root, int x, Node[] suc) {
        if (root == null) {
            return;
        }

        if (root.data > x) {
            suc[0] = root;
            findsuc(root.left, x, suc);
        }

        if (root.data <= x) {
            findsuc(root.right, x, suc);
        }
    }

    public ArrayList<Node> findPreSuc(Node root, int x) {

        Node[] pre = new Node[1];   // acts like reference
        Node[] suc = new Node[1];

        findpre(root, x, pre);
        findsuc(root, x, suc);

        ArrayList<Node> ans = new ArrayList<>();
        ans.add(pre[0]);
        ans.add(suc[0]);

        return ans;
    }
}