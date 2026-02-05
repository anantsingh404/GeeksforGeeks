class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int i = 0, j = 0,cnt = 0 , ans = 0;
        while(j < arr.size()){
            if(arr[j] == 0){
                cnt++;
            }

            while(cnt > k){
                if(arr[i] == 0){
                    cnt--;
                }
                i++;
            }
            ans = max(ans,j - i + 1);
            j++;
        }
        return ans;
    }
};
