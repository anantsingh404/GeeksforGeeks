class Solution {
    static ArrayList<Integer> diagView(int mat[][]) {
        // code here
        int n=mat.length;
        int m=mat[0].length;
        ArrayList<Integer>ans=new ArrayList<>();
        for(int j=0;j<m;j++){
            int i=0;
            int k=j;
            while(k>=0 && j<n)
            {
                ans.add(mat[i][k]);
                i++;
                k--;
            }
        }
        for(int i=1;i<n;i++){
            int j=m-1;
            int k=i;
            while(j>=0 && k<n)
            {
                ans.add(mat[k][j]);
                j--;
                k++;
            }
        }
        return ans;
        
    }
}
