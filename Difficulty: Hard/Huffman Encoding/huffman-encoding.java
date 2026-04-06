class Solution {
    static class Node {
        char ch;
        int freq;
        Node left, right;
        int minIndex; // smallest index in subtree
        
        Node(char ch, int freq, int index) {
            this.ch = ch;
            this.freq = freq;
            this.minIndex = index;
        }
        
        Node(int freq, Node left, Node right) {
            this.ch = '-';
            this.freq = freq;
            this.left = left;
            this.right = right;
            this.minIndex = Math.min(left.minIndex, right.minIndex);
        }
    }
    
   public ArrayList<String> huffmanCodes(String s, int f[]) {
    int n = s.length();
    
    // Edge case: only one character
    if (n == 1) {
        ArrayList<String> res = new ArrayList<>();
        res.add("0");
        return res;
    }
    
    PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
        if (a.freq != b.freq) return a.freq - b.freq;
        return a.minIndex - b.minIndex;
    });
    
    for (int i = 0; i < n; i++) {
        pq.add(new Node(s.charAt(i), f[i], i));
    }
    
    while (pq.size() > 1) {
        Node left = pq.poll();
        Node right = pq.poll();
        
        Node parent = new Node(left.freq + right.freq, left, right);
        pq.add(parent);
    }
    
    Node root = pq.poll();
    
    ArrayList<String> result = new ArrayList<>();
    generateCodes(root, "", result);
    
    return result;
}
    
    private void generateCodes(Node root, String code, ArrayList<String> result) {
        if (root == null) return;
        
        // Leaf node
        if (root.left == null && root.right == null) {
            result.add(code);
            return;
        }
        
        generateCodes(root.left, code + "0", result);
        generateCodes(root.right, code + "1", result);
    }
}