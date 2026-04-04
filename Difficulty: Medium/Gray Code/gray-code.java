import java.util.*;

class Solution {
    
    public ArrayList<String> graycode(int n) {
        
        // Base case
        if (n == 1) {
            ArrayList<String> base = new ArrayList<>();
            base.add("0");
            base.add("1");
            return base;
        }

        // Recursive call
        ArrayList<String> ans = graycode(n - 1);
        ArrayList<String> res = new ArrayList<>();

        // Add '0' prefix
        int i = 0;
        while (i < ans.size()) {
            res.add("0" + ans.get(i));
            i++;
        }

        // Add '1' prefix in reverse
        i = ans.size() - 1;
        while (i >= 0) {
            res.add("1" + ans.get(i));
            i--;
        }

        return res;
    }
}