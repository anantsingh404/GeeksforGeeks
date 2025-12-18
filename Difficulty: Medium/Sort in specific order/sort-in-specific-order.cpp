class Solution {
  public:
    void sortIt(vector<int>& arr) {
         int a=-1;
       for(int i=0;i<arr.size();i++)if(arr[i]%2) swap(arr[++a],arr[i]);
       sort(arr.begin(),arr.begin()+a+1, greater<int>());
       sort(arr.begin()+a+1,arr.end());// code here
        
    }
};