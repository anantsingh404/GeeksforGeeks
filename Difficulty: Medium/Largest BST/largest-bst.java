class temp {
    int mini;
    int maxi;
    int count;
    int flag;

    temp(int mini, int maxi, int count, int flag) {
        this.mini = mini;
        this.maxi = maxi;
        this.count = count;
        this.flag = flag;
    }
}

class Solution {

    static int ans;

    static temp solve(Node root) {

        // Base case
        if (root == null) {
            return new temp(Integer.MAX_VALUE, Integer.MIN_VALUE, 0, 1);
        }

        temp left = solve(root.left);
        temp right = solve(root.right);

        // Check BST condition
        if (left.flag == 1 && right.flag == 1) {

            if (left.maxi < root.data && right.mini > root.data) {

                int size = left.count + right.count + 1;

                ans = Math.max(ans, size);

                int newMin = Math.min(root.data, left.mini);
                int newMax = Math.max(root.data, right.maxi);

                return new temp(newMin, newMax, size, 1);
            }
        }

        // Not BST
        return new temp(Integer.MIN_VALUE, Integer.MAX_VALUE, 0, 0);
    }

    static int largestBst(Node root) {

        ans = 0;

        solve(root);

        return ans;
    }
}