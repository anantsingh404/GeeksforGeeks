class Solution {
    public int countSubarrays(int[] arr) {
        // code here
        Stack<Integer>st=new Stack<>();
        int n=arr.length;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
           while(!st.empty() && arr[st.peek()]>=arr[i])
           {
               st.pop();
           }
           if(st.empty())
           {
               ans+=(n-i);
           }
           else
           {
               ans+=st.peek()-i;
           }
          // System.out.println(ans);
           st.push(i);
        }
        return ans;
    }
}
