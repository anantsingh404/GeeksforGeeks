class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // Your code here
         if(arr.size() < 3){
            return -1;
        }
        sort(arr.begin(),arr.end());
        if(arr.size() >= 3){
            return arr[arr.size()-3];
        }
        
        
    }
};