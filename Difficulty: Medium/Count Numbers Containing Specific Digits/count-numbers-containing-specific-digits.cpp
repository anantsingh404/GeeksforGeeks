class Solution {
  public:
 
    int countValid(int n, vector<int>& arr) {
        // code here
        
         int totalWays = 9 * pow(10, n-1);
        int m = 10 - arr.size(); 
        int unwanted = pow(m, n);
        if(find(arr.begin(), arr.end(), 0) == arr.end()){
            unwanted -= pow(m, n-1);
        }
        return totalWays - unwanted;
    }
};
