class Solution {
    public ArrayList<Integer> reducePairs(int[] arr) {
        
        Stack<Integer> st = new Stack<>();
        
        for (int x : arr) {
            
            if (st.isEmpty() || (st.peek()>0 && x>0) || (st.peek()<0 && x<0)) 
            {
                st.push(x);
            } 
            else
            {
                
                    // collision case
                    boolean temp=false;
                    while (!st.isEmpty() && st.peek()*x<0 && Math.abs(st.peek()) < Math.abs(x)) {
                        st.pop();
                    }
                    
                    if (!st.isEmpty() && st.peek()*x<0 && Math.abs(st.peek()) == Math.abs(x)) {
                        st.pop(); // both removed
                        temp=true;
                        continue;
                    }
                    
                    if (temp==true) {
                        continue; // current destroyed
                    }
                    if(st.isEmpty())
                    {
                    st.push(x);
                    }
            }
            }
             ArrayList<Integer> ans = new ArrayList<>();
        
        while (!st.isEmpty()) {
            ans.add(st.pop());
        }
        
        Collections.reverse(ans);
        return ans;
        
        
       
    }
}