class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
          sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
       int cost = 0;
        int rowPiece = 1;
        int colPiece = 1;
        int i = 0,j=0;
        while(i < m-1 && j < n-1){
            if(x[i] >= y[j]){
                cost += rowPiece*x[i];
                i++;
                colPiece += 1;
            }else{
                cost += colPiece*y[j];
                j++;
                rowPiece += 1;
            }
        }
        while(i < m-1){
            cost += rowPiece*x[i];
            i++;
        }
        while(j < n-1){
            cost += colPiece*y[j];
            j++;
        }
        return cost;
    }
};
