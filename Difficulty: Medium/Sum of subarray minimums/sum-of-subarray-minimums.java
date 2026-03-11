class Solution {
    public int sumSubMins(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Stack<Integer> st = new Stack<>();

        for(int i = 0; i < n; i++)
        {
            left[i] = 1;
            right[i] = 1;
        }

        st.push(0);

        for(int i = 1; i < n; i++)
        {
            while(!st.empty() && arr[i] < arr[st.peek()])
            {
                st.pop();
            }

            if(st.empty())
            {
                left[i] = i + 1;
            }
            else
            {
                left[i] = i - st.peek();
            }

            st.push(i);
        }

        while(!st.empty())
        {
            st.pop();
        }

        st.push(n - 1);

        for(int i = n - 2; i >= 0; i--)
        {
            while(!st.empty() && arr[i] <= arr[st.peek()])
            {
                st.pop();
            }

            if(st.empty())
            {
                right[i] = n - i;
            }
            else
            {
                right[i] = st.peek() - i;
            }

            st.push(i);
        }

        long ans = 0;

        for(int i = 0; i < n; i++)
        {
            ans += (long)arr[i] * left[i] * right[i];
        }

        return (int)ans;
    }
}